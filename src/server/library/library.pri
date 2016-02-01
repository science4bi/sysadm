
CONFIG 	+=  c++11

HEADERS	+= 	$${PWD}/sysadm-global.h \
                $${PWD}/sysadm-general.h \
                $${PWD}/sysadm-iocage.h \
                $${PWD}/sysadm-lifepreserver.h \
                $${PWD}/sysadm-network.h \
                $${PWD}/sysadm-firewall.h \
                $${PWD}/sysadm-servicemanager.h\
                $${PWD}/sysadm-systeminfo.h\
                $${PWD}/sysadm-update.h \
                $${PWD}/sysadm-usermanager.h

SOURCES	+=	$${PWD}/NetDevice.cpp \
                $${PWD}/sysadm-general.cpp \
                $${PWD}/sysadm-iocage.cpp \
                $${PWD}/sysadm-lifepreserver.cpp \
                $${PWD}/sysadm-network.cpp \
                $${PWD}/sysadm-firewall.cpp \
                $${PWD}/sysadm-servicemanager.cpp \
                $${PWD}/sysadm-systeminfo.cpp \
                $${PWD}/sysadm-update.cpp \
                $${PWD}/sysadm-usermanager.cpp

