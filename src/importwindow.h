#ifndef GTKMM_IMPORTWINDOW_H
#define GTKMM_IMPORTWINDOW_H

#include <gtkmm.h>

class ImportWindow : public Gtk::Window {
public:
	ImportWindow();
	virtual ~ImportWindow();

protected:
	// Signal handlers:
	void on_button_file_clicked();
	void on_button_folder_clicked();

	// Child widgets:
	Gtk::ButtonBox m_ButtonBox;
	Gtk::Button m_Button_File, m_Button_Folder;
};

#endif // GTKMM_IMPORTWINDOW_H