use druid::{
    widget::TextBox,
    widget::{Button, Checkbox, Flex, Label, List},
    Widget, WidgetExt,
};

use crate::{controllers::ComputerAppController, data::*};
use crate::controllers::AddComputerController;

fn new_computer_textbox() -> impl Widget<AppState> {
    let new_computer_textbox = TextBox::new()
        .with_placeholder("Computer Name")
        .expand_width()
        .lens(AppState::new_computer)
        .controller(AddComputerController);
    let new_computer_ip_textbox = TextBox::new()
        .with_placeholder("Computer IP")
        .expand_width()
        .lens(AppState::new_ip)
        .controller(AddComputerController);;

    let add_computer_button = Button::new("Add").on_click(AppState::click_add);

    Flex::row()
        .with_flex_child(new_computer_textbox, 1.)
        .with_flex_child(new_computer_ip_textbox, 1.)
        .with_child(add_computer_button)
}

fn computer_item() -> impl Widget<ComputerItem> {
    // let checkbox = Checkbox::new("").lens(ComputerItem::done);
    let connected = Label::new(|data: &ComputerItem, _env: &_| {
        if data.done {
            "Connected"
        } else {
            "Not Connected"
        }
    });
    let label = Label::raw().lens(ComputerItem::name);
    let ips = Label::raw().lens(ComputerItem::ip);

    let delete_button = Button::new("Delete").on_click(ComputerItem::click_delete);

    Flex::row()
        .with_child(connected)
        .with_child(Label::new(" | Name: ").with_text_size(14.))
        .with_child(label)
        .with_child(Label::new(" | IP: "))
        .with_child(ips)
        .with_flex_spacer(1.)
        .with_child(delete_button)
        .controller(ComputerAppController)
}

pub fn build_ui() -> impl Widget<AppState> {
    let clear_completed_button = Button::new("Clear completed").on_click(AppState::clear_completed);

    Flex::column()
        .with_child(new_computer_textbox())
        .with_child(List::new(computer_item).lens(AppState::computers))
        .with_flex_spacer(1.)
        .with_child(clear_completed_button)
}