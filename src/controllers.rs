use druid::{widget::Controller, Env, UpdateCtx, Widget, EventCtx, Event, KbKey, HotKey};

use crate::data::*;
use crate::delegate::SAVE;

pub struct AddComputerController;

impl<W: Widget<AppState>> Controller<AppState, W> for AddComputerController {
    fn event(
        &mut self,
        child: &mut W,
        ctx: &mut EventCtx,
        event: &Event,
        data: &mut AppState,
        env: &Env,
    ) {
        match event {
            Event::KeyDown(k_e) if HotKey::new(None, KbKey::Enter).matches(k_e) => {
                data.add_computer();
                ctx.set_handled();
            }
            _ => {}
        }
        child.event(ctx, event, data, env);
    }
}

pub struct ComputerAppController;

impl<W: Widget<ComputerItem>> Controller<ComputerItem, W> for ComputerAppController {
    fn update(
        &mut self,
        child: &mut W,
        ctx: &mut UpdateCtx,
        old_data: &ComputerItem,
        data: &ComputerItem,
        env: &Env,
    ) {
        if old_data.done != data.done {
            ctx.submit_command(SAVE);
        }
        child.update(ctx, old_data, data, env);
    }
}