#ifndef GTKMM_GUI_H
#define GTKMM_GUI_H
#include "importwindow.h"
#include "model/contact.h"
#include <gtkmm.h>
#include <gtkmm/application.h>

namespace G {
	class ReachGUI {
	public:
		ReachGUI(std::string appid);
		// virtual ~ReachGUI();
		Glib::RefPtr<Gtk::Application> app;
		void show_contact(Contact contact);

		// Signal handlers:
		void close_hide_window();
		void on_app_activate();
		void on_close_importwindow();
		void on_import();

		ImportWindow *importw_;

	private:
		void set_contact_name(string name);
		void set_contact_photo();

	};
} // namespace G

#endif // GTKMM_GUI_H