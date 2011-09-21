; Rooms Make File
; ---------------
; Brings together all the modules and libraries required to run Rooms

core = 7.x
api = 2

;Core project
projects[] = drupal

;Building Blocks
projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.0-rc1"

projects[views][subdir] = "contrib"
projects[views][version] = "3.0-rc1"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.0-beta10"

projects[rules][subdir] = "contrib"
projects[rules][version] = "2.0-beta2"

projects[commerce][subdir] = "contrib"
projects[commerce][version] = "1.0"

projects[date][subdir] = "contrib"
projects[date][version] = "2.0-alpha4"

projects[addressfield][subdir] = "contrib"
projects[addressfield][version] = "1.0-beta2"

projects[colorbox][subdir] = "contrib"
projects[colorbox][version] = "1.1"

;Rooms
projects[rooms][download][type] = "git"
projects[rooms][download][module] = "rooms"
projects[rooms][download][revision] = "master"

;libraries
libraries[fullcalendar][download][type] = "get"
libraries[fullcalendar][download][url] = "http://arshaw.com/fullcalendar/downloads/fullcalendar-1.5.1.zip"
libraries[fullcalendar][directory_name] = "fullcalendar"
libraries[fullcalendar][destination] = "libraries"

libraries[colorbox][download][type] = "get"
libraries[colorbox][download][url] = "http://colorpowered.com/colorbox/colorbox.zip"
libraries[colorbox][directory_name] = "colorbox"
libraries[colorbox][destination] = "libraries"

