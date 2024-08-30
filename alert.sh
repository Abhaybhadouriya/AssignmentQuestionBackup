#!/bin/bash
# lock_gnome.sh

# Lock the screen
gsettings set org.gnome.desktop.screensaver lock-enabled true
xdg-screensaver lock
