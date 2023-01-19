use std::{
    fs::File,
    io::{BufReader, Error},
};

use druid::{im::Vector, Data, Env, EventCtx, Lens};
use serde::{Deserialize, Serialize};
use uuid::Uuid;

use crate::delegate::DELETE;

#[derive(Clone, Data, Lens)]
pub struct AppState {
    new_computer: String,
    new_ip: String,
    computers: Vector<ComputerItem>,
}

impl AppState {
    pub(crate) fn add_computer(&mut self) {
        self.computers.push_front(ComputerItem::new(&self.new_computer, &self.new_ip));
        self.new_computer = "".into();
        self.new_ip = "".into();
        self.save_to_json().unwrap();
    }

    pub fn click_add(_ctx: &mut EventCtx, data: &mut Self, _env: &Env) {
        data.add_computer();
    }

    pub fn save_to_json(&self) -> Result<(), Error> {
        let computer_vec: Vec<ComputerItem> = self.computers.iter().map(|item| item.to_owned()).collect();
        let serialized = serde_json::to_string_pretty(&computer_vec)?;
        std::fs::write("computers.json", serialized)?;
        Ok(())
    }

    pub fn load_from_json() -> Self {
        let file = File::open("computers.json");

        match file {
            Ok(file) => {
                let reader = BufReader::new(file);
                let computers: Vec<ComputerItem> = serde_json::from_reader(reader).unwrap_or(vec![]);
                Self {
                    computers: Vector::from(computers),
                    new_computer: String::new(),
                    new_ip: String::new(),
                }
            }
            Err(_) => Self {
                computers: Vector::new(),
                new_computer: String::new(),
                new_ip: String::new(),
            },
        }
    }

    pub fn clear_completed(_ctx: &mut EventCtx, data: &mut Self, _env: &Env) {
        data.computers.retain(|item| !item.done);

        data.save_to_json().unwrap();
    }

    pub fn delete_computer(&mut self, id: &Uuid) {
        self.computers.retain(|item| &item.id != id);

        self.save_to_json().unwrap();
    }
}

#[derive(Clone, Data, Lens, Serialize, Deserialize)]
pub struct ComputerItem {
    #[data(same_fn = "PartialEq::eq")]
    pub id: Uuid,
    pub done: bool,
    pub name: String,
    pub ip: String,
}

impl ComputerItem {
    pub fn new(name: &str, cip: &str) -> Self {
        Self {
            id: Uuid::new_v4(),
            done: false,
            name: name.into(),
            ip: cip.into(),
        }
    }

    pub fn click_delete(ctx: &mut EventCtx, data: &mut Self, _env: &Env) {
        ctx.submit_command(DELETE.with(data.id));
    }
}