# Troubleshooting

Here is a list of issues I encountered that may be useful for other devs:

1. when editing the `.glade` file it helps to completely `rm -rf` the `build` directory and start over. Before doing this, even with a `make clean`, It seemed like GTKBuilder was not picking up on the changes made to the `.glade` file (which in this case was adding a new ID to an existin button)