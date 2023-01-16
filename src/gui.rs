use std::sync::Arc;
use std::sync::atomic::{AtomicBool, Ordering};
use druid::{theme, AppLauncher, Color, Data, Lens, LocalizedString, RenderContext, Widget, WidgetExt, WindowDesc, UnitPoint, Env};

use druid::widget::{CrossAxisAlignment, Flex, Label, Painter, TextBox};
use enigo::Enigo;

const VERTICAL_WIDGET_SPACING: f64 = 20.0;
const TEXT_BOX_WIDTH: f64 = 200.0;

#[derive(Clone, Data, Lens)]
pub struct HelloState {
    name: String,
}

pub struct Guistate {
    window: WindowDesc<HelloState>,
    state: HelloState,
}

pub fn build_root_widget() -> impl Widget<HelloState> {
    // a label that will determine its text based on the current app data.
    let label = Label::new(|data: &HelloState, _env: &Env| {
        if data.name.is_empty() {
            "Hello anybody!?".to_string()
        } else {
            format!("Hello {}!", data.name)
        }
    })
        .with_text_size(32.0);

    // a textbox that modifies `name`.
    let textbox = TextBox::new()
        .with_placeholder("Who are we greeting?")
        .with_text_size(18.0)
        .fix_width(TEXT_BOX_WIDTH)
        .lens(HelloState::name);

    // arrange the two widgets vertically, with some padding
    Flex::column()
        .with_child(label)
        .with_spacer(VERTICAL_WIDGET_SPACING)
        .with_child(textbox)
        .align_vertical(UnitPoint::CENTER)
}

pub fn init() -> Guistate {
    let window = WindowDesc::new(build_root_widget())
        .window_size((223., 300.))
        .resizable(false)
        .title(
            "Kouse",
        );

    let stats = Guistate {
        window: window,
        state : HelloState {
            name: "World".into(),
        },
    };

    return stats;
}

pub fn runner(state: Guistate) {
    AppLauncher::with_window(state.window)
        .log_to_console()
        .launch(state.state)
        .expect("launch failed");
}