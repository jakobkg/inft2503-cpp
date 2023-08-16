#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::Box box;
  Gtk::Entry firstname;
  Gtk::Label fname_label;
  Gtk::Entry lastname;
  Gtk::Label lname_label;
  Gtk::Button button;
  Gtk::Label label;

  Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
    button.set_label("Combine names");
    button.set_sensitive(false);

    fname_label.set_text("First name");
    lname_label.set_text("Last name");

    // Add components to the box
    box.pack_start(fname_label);
    box.pack_start(firstname);
    box.pack_start(lname_label);
    box.pack_start(lastname);
    box.pack_start(button);
    box.pack_start(label);

    add(box);   // Add vbox to window
    show_all(); // Show all widgets

    // Oppdaterer knappens sensitivitet (på/av) basert på om tekst-feltene har innhold
    auto update_button_sensitivity = [this]() {
      button.set_sensitive(
        firstname.get_text_length() > 0 &&
        lastname.get_text_length() > 0
      );
    };

    // Kombinerer navnene og viser dem i label, om knappen er aktiv
    auto combine_names = [this]() {
      if (button.get_sensitive())
        label.set_text("Names combined: " + firstname.get_text() + " " + lastname.get_text());
    };

    // Oppdater knappens status hver gang tekst-feltene redigeres
    firstname.signal_changed().connect(update_button_sensitivity);
    lastname.signal_changed().connect(update_button_sensitivity);

    // Kombiner navnene når knappen trykkes på med mus eller tastatur
    button.signal_clicked().connect(combine_names);
    button.signal_activate().connect(combine_names);

    // Kombiner navnene når man trykker Enter i tekst-feltene
    firstname.signal_activate().connect(combine_names);
    lastname.signal_activate().connect(combine_names);

  }
};

int main() {
  auto app = Gtk::Application::create();
  Window window;
  window.set_title("Øving 4");
  return app->run(window);
}
