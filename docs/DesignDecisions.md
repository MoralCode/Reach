# Reach app Design Decisions

## App Structure
The app should hopefully follow an MVC-like architecture with Model, View, and Controller roughly mapping to the Model, UI, and Application Tiers. I've used the MVC pattern in the past so this seems like a good choice to help keep the code separated enough to allow it to be flexible without breaking things.



## The Code

### UI Tier
 
version 3.10 was selected for the .glade file because it works and is apparrently a version that is already availale in Debian/ubuntu repos (see https://developer.gnome.org/gtkmm-tutorial/stable/sec-install-unix-and-linux.html.en) :

> The package names will not change when new API/ABI-compatible versions of gtkmm are released. Otherwise they would not be API/ABI-compatible. So don't be surprised, for instance, to find gtkmm 3.8 supplied by Debian's libgtkmm-3.0-dev package. 

Despite using an MVC pattern, I'm not sure how it should be structured. Does the UI Tier/View code need to be passed a reference to an Application Tier/Controller Class so it can fetch a contact to display it? How should UI tier to pass an identifier of what contact name was clicked on from the list up to the application tier so the application tier can tell it to display a particular contact. Both of these require a reference to the application tier in the UI tier, which seems sorta questionable to me, although i guess it makes sense since the point of the app tier is to connect the model and UI tiers?

#### Packing into a resource file

Reach uses Glib's `Resource` feature to effectively compile the .glade file into the app itself so as not to require any additional files to be installed alongside the binary. this resource is then fetched and registered as global in `main.cpp` so that it is available to use when `gui.cpp` calls `create_from_resource` to create the `Gtk::Builder` object. Admittedly this was a fairly arbitrary decision thats more down to developer preference than anything else.

### Application Tier

#### Database
The current plan is to just use a directory of `.vcf` files for simplicity. This means theres less overhead of having to deal with databases while things are laid out. In future there may arise a need to use a database of some kind, i.e. for searching for a contact.


##### Future Plans
[ODB](https://www.codesynthesis.com/products/odb/doc/manual.xhtml#1) is an ORM (Object Relation mapper) for C++ and makes it easy to store and retrieve C++ objects from a database without any other reqirements like inheriting from a base class or including special hidden data like other ORM's that i've worked with in the past. It also seems like (from a [stackoverflow post by someone who works on it](https://stackoverflow.com/a/13648509/)) it supports schema evolution - or the ability to generate the detabase calls necessary to upgrade the database automatically, which is awesome since i'd prefer not to have to write that for this simple app. Ultimately, ODB was chosen because it is one of the only ORM's for C++ that I could immediately find.

Another perk of using an ORM is that it makes it easier to swap out the underlying database, which helps because I basically just picked SQLite arbitrarily as its popular, easy, and contained in one file. 


### Model Tier


### Libraries used
I remember doing a bunch of reserach on config file parsers and for some reason ended up settling on [libconfig](https://hyperrealm.github.io/libconfig/). I think part of that decision was support for pre C++11 stuff but im not sure if I stopped caring about that before or after instlaling this. 

## Testing
### Unit Testing

Googletest was chosen as the unit test framework due to its popularity. To date it still hasnt been setup properly as I am still unsure of whether UI-tier signal handlers for GTK need to be unit tested or not, and if so, how to unit test a protected method despite the internet seemingly saying that testing "private" methods is bad.