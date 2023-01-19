use druid::{AppDelegate, Command, DelegateCtx, Env, Handled, Selector, Target};
use uuid::Uuid;

use crate::data::AppState;

pub const SAVE: Selector = Selector::new("computer.save");
pub const DELETE: Selector<Uuid> = Selector::new("computer.delete");

pub struct Delegate;

impl AppDelegate<AppState> for Delegate {
    fn command(
        &mut self,
        _ctx: &mut DelegateCtx,
        _target: Target,
        cmd: &Command,
        data: &mut AppState,
        _env: &Env,
    ) -> Handled {
        if cmd.is(SAVE) {
            data.save_to_json().unwrap();
            Handled::Yes
        } else if let Some(id) = cmd.get(DELETE) {
            data.delete_computer(id);
            Handled::Yes
        } else {
            println!("cmd forwarded: {:?}", cmd);
            Handled::No
        }
    }
}