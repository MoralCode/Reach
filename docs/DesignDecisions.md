# Reach app Design Decisions

## UI
 
version 3.10 was selected for the .glade file because it works and is apparrently a version that is already availale in Debian/ubuntu repos (see https://developer.gnome.org/gtkmm-tutorial/stable/sec-install-unix-and-linux.html.en) :

> The package names will not change when new API/ABI-compatible versions of gtkmm are released. Otherwise they would not be API/ABI-compatible. So don't be surprised, for instance, to find gtkmm 3.8 supplied by Debian's libgtkmm-3.0-dev package. 

### Packing into a resource file

Reach uses Glib's `Resource` feature to effectively compile the .glade file into the app itself so as not to require any additional files to be installed alongside the binary. this resource is then fetched and registered as global in `main.cpp` so that it is available to use when `gui.cpp` calls `create_from_resource` to create the `Gtk::Builder` object. Admittedly this was a fairly arbitrary decision thats more down to developer preference than anything else.