#!/bin/sh

echo "add-auto-load-safe-path /home/vagrant/project/.gdbinit" > $HOME/.gdbinit
echo "alias v=vim" >> $HOME/.bashrc

sudo yum install vim gdb
