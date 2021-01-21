#ifndef GTKMM_GUI_H
#define GTKMM_GUI_H
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

	// 	// Child widgets:
	// 	// Gtk::ButtonBox m_ButtonBox;
	// 	// Gtk::Button m_Button_File, m_Button_Folder;

	};
} // namespace G

#endif // GTKMM_GUI_H