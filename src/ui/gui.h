#ifndef GTKMM_GUI_H
#define GTKMM_GUI_H
#include "importwindow.h"
#include <gtkmm.h>
#include <gtkmm/application.h>

namespace G {
	class ReachGUI {
	public:
		ReachGUI(std::string appid);
		// virtual ~ReachGUI();
		Glib::RefPtr<Gtk::Application> app;

		// Signal handlers:
		void close_hide_window();
		void on_app_activate();
		void on_close_importwindow();
		void on_import();

		ImportWindow *importw_;
		
	};
} // namespace G

#endif // GTKMM_GUI_H