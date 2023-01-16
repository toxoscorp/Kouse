use std::sync::Arc;
use std::sync::atomic::{AtomicBool, Ordering};
use druid::{theme, AppLauncher, Color, Data, Lens, LocalizedString, RenderContext, Widget, WidgetExt, WindowDesc, UnitPoint, Env};

use druid::widget::{CrossAxisAlignment, Flex, Label, Painter, TextBox};
use enigo::Enigo;

pub mod gui;

struct Kouse {
    enigo: Enigo,
    running: Arc<AtomicBool>,
    state: gui::Guistate,
}

pub fn main() {
    let kouse = Kouse {
        enigo: Enigo::new(),
        running: Arc::new(AtomicBool::new(true)),
        state: gui::init(),
    };

    let running_clone = kouse.running.clone();
    let handle = std::thread::spawn(move|| {
        let mut enigo = Enigo::new();
        while running_clone.load(Ordering::Relaxed) {
            let cursor_location: (i32, i32) = Enigo::mouse_location();
            println!("Mouse location: {:?}", cursor_location);
            println!("Stats: {:?}", running_clone);
            std::thread::sleep(std::time::Duration::from_millis(500));
        }
        println!("Thread finished");
    });

    gui::runner(kouse.state);

    running.store(false, Ordering::Relaxed);
    handle.join().unwrap();
}