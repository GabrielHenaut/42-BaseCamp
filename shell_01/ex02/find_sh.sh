find . -name '*.sh' -type f | rev | cut -d '/' -f 1 | cut -d '.' -f 2 | rev
