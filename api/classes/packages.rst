.. _packages:

packages
********

Resources related to the packages class.

.. _webclient:

webclient
=========

The webclient resource is used to...

For up-to-date request options, use :command:`help [pkg | pbi | jail | search]`  to query the sysadm daemon for the available options for the specified parameter. This section covers most
of the common queries and replies.

.. _note: whenever *<jail>* is used in a query, it can be replaced by 
   *#system* to probe the local system or by a jail ID for to specify a particular jail on the system.

.. _Event Notifications:
   
Event Notifications
-------------------

The dispatcher provides support for the client to subscribe to per-connection event notifications. Event requests use the following parameters:

+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+
| **Parameter**                   | **Value**     | **Description**                                                                                                      |
|                                 |               |                                                                                                                      |
+=================================+===============+======================================================================================================================+
| id                              |               | any unique value for the request; examples include a hash, checksum, or uuid                                         |
|                                 |               |                                                                                                                      |
+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+
| name                            | subscribe     | use the desired action                                                                                               |
|                                 | unsubscribe   |                                                                                                                      |
+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+
| namespace                       | events        |                                                                                                                      |
|                                 |               |                                                                                                                      |
+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+
| args                            | dispatcher    |                                                                                                                      |
|                                 |               |                                                                                                                      |
+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+

To subscribe from dispatcher events:

.. code-block:: json

  {
  "namespace" : "events",
  "name" : "subscribe",
  "id" : "sampleID",
  "args" : ["dispatcher"]
  }

To unsubscribe from dispatcher events:
  
.. code-block:: json

  {
  "namespace" : "events",
  "name" : "unsubscribe",
  "id" : "sampleID",
  "args" : ["dispatcher"]
  }

This response indicates that a dispatcher event occurred:

.. code-block:: json

  {
  "namespace" : "events",
  "name" : "event",
  "id" : "",
  "args" : {
    "name" : "dispatcher",
    "args" : "<message"
    }
  }

.. _Dispatcher Usage:
  
Dispatcher Usage
----------------

Dispatcher requests use the following parameters:

+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+
| **Parameter**                   | **Value**     | **Description**                                                                                                      |
|                                 |               |                                                                                                                      |
+=================================+===============+======================================================================================================================+
| id                              |               | any unique value for the request; examples include a hash, checksum, or uuid                                         |
|                                 |               |                                                                                                                      |
+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+
| name                            | dispatcher    |                                                                                                                      |
|                                 |               |                                                                                                                      |
+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+
| namespace                       | rpc           |                                                                                                                      |
|                                 |               |                                                                                                                      |
+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+
| args                            |               | values vary by type of request                                                                                       |
|                                 |               |                                                                                                                      |
+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+

The following arguments are supported:

* iocage {cmd} [args]

* queue {pkg|pbi} {origin} {install/delete/info} {__system__|<jailname>}
   
* pkgupdate {__system__|<jailname>}
   
* service {start|stop|restart} {servicetag} {servicerc} {__system__|<jid>}
   
* getcfg {pbicdir} {__system__|<jid>} {key}
   
* setcfg {pbicdir} {__system__|<jid>} {key} {value}
   
* donecfg {pbicdir} {__system__|<jid>}
   
* daemon
   
* status
   
* results
   
* log {hash}
 
.. _General sysadm Information:

General sysadm Information
--------------------------

Queries for information from the sysadm daemon use the following parameters:

+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+
| **Parameter**                   | **Value**     | **Description**                                                                                                      |
|                                 |               |                                                                                                                      |
+=================================+===============+======================================================================================================================+
| id                              |               | any unique value for the request; examples include a hash, checksum, or uuid                                         |
|                                 |               |                                                                                                                      |
+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+
| name                            | sysadm        |                                                                                                                      |
|                                 |               |                                                                                                                      |
+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+
| namespace                       | rpc           |                                                                                                                      |
|                                 |               |                                                                                                                      |
+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+
| args                            |               | comma delimited list of information to request                                                                       |
|                                 |               |                                                                                                                      |
+---------------------------------+---------------+----------------------------------------------------------------------------------------------------------------------+

The following *args* are supported. Note that 
*"app-summary"* and 
*"cage-summary"* are specifically designed for getting enough information for lots of small app icons in fewer sysadm requests. 

+---------------------------------+----------------------------------------------------------------------------------------------------------------------+
| **Value**                       | **Description**                                                                                                      |
|                                 |                                                                                                                      |
+=================================+======================================================================================================================+
| startsync                       | Manually start a system information sync (usually unnecessary)                                                       |                                                                                                                    
|                                 |                                                                                                                      |
+---------------------------------+----------------------------------------------------------------------------------------------------------------------+
| needsreboot                     | Check if the system needs to reboot to finish updates                                                                |
|                                 |                                                                                                                      |
+---------------------------------+----------------------------------------------------------------------------------------------------------------------+
| isupdating                      | Check if the system is currently performing updates                                                                  |
|                                 |                                                                                                                      |
+---------------------------------+----------------------------------------------------------------------------------------------------------------------+
| hasupdates                      | Check if system updates are available                                                                                |
|                                 |                                                                                                                      |
+---------------------------------+----------------------------------------------------------------------------------------------------------------------+
| updatelog                       | Raw text output from the check for system updates                                                                    |
|                                 |                                                                                                                      |
+---------------------------------+----------------------------------------------------------------------------------------------------------------------+
| hasmajorupdates                 | Check if FreeBSD system updates are available                                                                        |
|                                 |                                                                                                                      |
+---------------------------------+----------------------------------------------------------------------------------------------------------------------+
| majorupdatelog                  | Details about the major update(s)                                                                                    |
|                                 |                                                                                                                      |
+---------------------------------+----------------------------------------------------------------------------------------------------------------------+
| hassecurityupdates              | Check if FreeBSD security updates are available                                                                      |
|                                 |                                                                                                                      |
+---------------------------------+----------------------------------------------------------------------------------------------------------------------+
| securityupdatelog               | Details about any security update(s)                                                                                 |
|                                 |                                                                                                                      |
+---------------------------------+----------------------------------------------------------------------------------------------------------------------+
| haspcbsdupdates                 | Check if any PC-BSD hotfixes are available                                                                           |
|                                 |                                                                                                                      |
+---------------------------------+----------------------------------------------------------------------------------------------------------------------+
| pcbsdupdatelog                  | Details about any PC-BSD hotfixes                                                                                    |
|                                 |                                                                                                                      |
+---------------------------------+----------------------------------------------------------------------------------------------------------------------+
| <jail> app-summary <pkg origin> | Summary of information for an application                                                                            |
|                                 |                                                                                                                      |
+---------------------------------+----------------------------------------------------------------------------------------------------------------------+
| cage-summary <origin>           | Summary of information for a PBI cage                                                                                |
|                                 |                                                                                                                      |
+---------------------------------+----------------------------------------------------------------------------------------------------------------------+

**Request**

.. code-block:: json

  {
  "namespace" : "rpc",
  "name" : "sysadm",
  "id" : "someUniqueID",
  "args" : ["needsreboot", "hasupdates", "updatelog", "#system app-summary mail/thunderbird", "cage-summary multimedia/plexmediaserver"]
  }

As seen in the following example response, the *"app-summary"* return array is: 

* pkg origin
* name
* version
* icon path
* rating (out of 5)
* type
* comment
* configuration directory
* isInstalled
* canRemove

The *"cage-summary"* return array is: 

* origin
* name
* icon path
* architecture
* FreeBSD version

**Response**

.. code-block:: json

  {
    "args": {
        "#system app-summary mail/thunderbird": [
            "mail/thunderbird",
            "Thunderbird",
            "38.2.0_1",
            "/var/db/pbi/index/mail/thunderbird/icon.png",
            "5.00",
            "Graphical",
            "Mozilla Thunderbird is standalone mail and news that stands above ",
            "/var/db/pbi/index/mail/thunderbird",
            "true",
            "true"
        ],
        "cage-summary multimedia/plexmediaserver": [
            "multimedia/plexmediaserver",
            "Plex Media Server",
            "/var/db/pbi/cage-index/multimedia/plexmediaserver/icon.png",
            "amd64",
            "10.1-RELEASE"
        ],
        "hasupdates": "false",
        "needsreboot": "false",
        "updatelog": "Checking for FreeBSD updates...<br>Your system is up to date!"
    },
    "id": "someUniqueID",
    "name": "response",
    "namespace": "rpc"
  }

.. _PBI Database Queries:

PBI and PKG Database Queries
----------------------------

The following query types are supported when gathering information about installed PBIs. Use the required command and its syntax in the *args* parameter of the request.

+----------------+---------------------------------+------------------------------------------------------------------------------------------------------------------------+
| **Query Type** | **Command**                     | **<info> Syntax**                                                                                                      |
|                |                                 |                                                                                                                        |
+================+=================================+========================================================================================================================+
| List           | "pbi list <info>"               | "[all/server/graphical/text]apps", "[all/server/graphical/text]cats", or "cages"                                       |
|                |                                 |                                                                                                                        |
+----------------+---------------------------------+------------------------------------------------------------------------------------------------------------------------+
| App            | "pbi app <pkg origin> <info>"   | "author", "category", "confdir", "dependencies", "origin", "plugins, "rating", "relatedapps", "screenshots",           |
|                |                                 | "type", "tags", "comment", "description", "license", "maintainer", "name", "options", or "website"                     |
|                |                                 |                                                                                                                        |
+----------------+---------------------------------+------------------------------------------------------------------------------------------------------------------------+
| Cage           | "pbi cage <origin> <info>"      | "icon", "name", "description", "arch" fbsdver", "git", "gitbranch", "screenshots", "tags", "website"                   |
|                |                                 |                                                                                                                        |
+----------------+---------------------------------+------------------------------------------------------------------------------------------------------------------------+
| Category       | "pbi cat <pkg category> <info>" | "icon", "name", "origin", "comment"                                                                                    |
|                |                                 |                                                                                                                        |
+----------------+---------------------------------+------------------------------------------------------------------------------------------------------------------------+

Here is an example of a list and an app query which request five types of information:

.. code-block:: json

 {
 "namespace" : "rpc",
 "name" : "sysadm",
 "id" : "someUniqueID",
 "args" : ["pbi list graphicalapps", "pbi list cages", "pbi app www/firefox author", "pbi app www/firefox category", "pbi list graphicalcats" ]
 }

And its response:

.. code-block:: json

  {
    "args": {
        "pbi app www/firefox author": "Mozilla",
        "pbi app www/firefox category": "Web",
        "pbi list cages": [
            "archivers/elephantdrive",
            "multimedia/plexmediaserver"
        ],
        "pbi list graphicalapps": [
            "math/R",
            "www/WebMagick",
            "editors/abiword",
            "audio/abraca",
      (SHORTENED FOR BREVITY - THIS IS USUALLY QUITE LONG)
            "x11/zenity",
            "security/zenmap",
            "games/zephulor",
            "www/zope213"
        ],
        "pbi list graphicalcats": [
            "accessibility",
            "archivers",
            "astro",
            "audio",
        (SHORTENED FOR BREVITY - THIS IS USUALLY QUITE LONG)	
            "x11-themes",
            "x11-toolkits",
            "x11-wm"
        ]
    },
    "id": "someUniqueID",
    "name": "response",
    "namespace": "rpc"
  }

Here is an example of a category query and its response:

.. code-block:: json

 {
 "namespace" : "rpc",
 "name" : "sysadm",
 "id" : "someUniqueID",
 "args" : ["pbi cat www name", "pbi cat www icon", "pbi cat www comment", "pbi cat www origin" ]
 }

**Response**

.. code-block:: json

  {
    "args": {
        "pbi cat www comment": "Web browsers, and other applications used for the web such as RSS readers",
        "pbi cat www icon": "/var/db/pbi/index/PBI-cat-icons/www.png",
        "pbi cat www name": "Web",
        "pbi cat www origin": "www"
    },
    "id": "someUniqueID",
    "name": "response",
    "namespace": "rpc"
  }

Here is an example of a cage query and its response:

.. code-block:: json

 {
 "namespace" : "rpc",
 "name" : "sysadm",
 "id" : "someUniqueID",
 "args" : ["pbi cage multimedia/plexmediaserver tags", "pbi cage multimedia/plexmediaserver website", "pbi cage multimedia/plexmediaserver description", "pbi cage multimedia/plexmediaserver name"]
 }

**Response**

.. code-block:: json

  {
    "args": {
        "pbi cage multimedia/plexmediaserver description": "Plex stores all of your audio, video, and photo files in your free Plex Media Server so you can access them from all your devices and stream from anywhere.",
        "pbi cage multimedia/plexmediaserver name": "Plex Media Server",
        "pbi cage multimedia/plexmediaserver tags": "streaming, multimedia, server",
        "pbi cage multimedia/plexmediaserver website": "https://plex.tv"
    },
    "id": "someUniqueID",
    "name": "response",
    "namespace": "rpc"
  }

Two types of queries are available for retrieving information from the PKG database:

+----------------+-------------------------------------------------+---------------------------------------------------------------------------------------------------------------+
| **Query Type** | **Command**                                     | **<info> Syntax**                                                                                             |
|                |                                                 |                                                                                                               |
+================+=================================================+===============================================================================================================+
| General        | "pkg <jail> <info>"                             | "remotelist", "installedlist", "hasupdates" (true/false returned), or "updatemessage"                         |
|                |                                                 |                                                                                                               |
+----------------+-------------------------------------------------+---------------------------------------------------------------------------------------------------------------+
| Individual     | "pkg <jail> <local/remote> <pkg origin> <info>" | "origin", "name", "version", "maintainer", "comment", "description", "website", "size", "arch", "message",    |
|                |                                                 | "dependencies", "rdependencies", "categories", "options", "license"                                           |
|                |                                                 |                                                                                                               |
+----------------+-------------------------------------------------+---------------------------------------------------------------------------------------------------------------+

Note that <local> is used for installed applications while <remote> is for information available on the global repository and might not match what is currently installed. For <local>
pkg queries, there are some additional <info> options: "timestamp", "isOrphan", "isLocked", "files", "users", and "groups".

When specifying a jail, precede the jail's name with a *#*:

**Request**

.. code-block:: json

 {
 "namespace" : "rpc",
 "name" : "sysadm",
 "id" : "someUniqueID",
 "args" : ["pkg #system installedlist", "pkg #system local mail/thunderbird version", "pkg #system remote mail/thunderbird version", "pkg #system local mail/thunderbird files" ]
 }

**Response**

.. code-block:: json

 {
    "args": {
        "pkg #system installedlist": [
            "graphics/ImageMagick",
            "devel/ORBit2",
            "graphics/OpenEXR",
            (SHORTENED FOR BREVITY - THIS GETS QUITE LONG)
            "archivers/zip",
            "devel/zziplib"
        ],
        "pkg #system local mail/thunderbird files": [
            "/usr/local/bin/thunderbird",
            "/usr/local/lib/thunderbird/application.ini",
            "/usr/local/lib/thunderbird/blocklist.xml",
            "/usr/local/lib/thunderbird/chrome.manifest",
            (SHORTENED FOR BREVITY - THIS GETS QUITE LONG)
            "/usr/local/share/applications/thunderbird.desktop",
            "/usr/local/share/pixmaps/thunderbird.png"
        ],
        "pkg #system local mail/thunderbird version": "38.2.0_1",
        "pkg #system remote mail/thunderbird version": "38.2.0_1"
    },
    "id": "someUniqueID",
    "name": "response",
    "namespace": "rpc"
 }

Both PBIs and PKGs support the following search query syntax: "<pkg/pbi> search <search term> [<pkg jail>/<pbi filter>] [result minimum]".

When performing a search, note that:

* The search query always returns an array of <pkg origin>, organized in order of priority where the first element is highest priority and the last element is the lowest priority.

* <pbi> probes the PBI database of end-user applications and is independent of what is actually available or installed. <pkg> searches all available and installed packages. whether or
  not they are designed for end-users.

* <pkg jail> may only be used for pkg searches and corresponds to normal <jail> syntax (using "#system" or jail ID). If a jail is not specified, it assumes a search for the
  local system (#system).

* <pbi filter> may only be used for PBI searches to restrict the type of application being looked for, and may be "all" "[not]graphical", "[not]server", and "[not]text". The
  default value is "all" if no option is supplied.

* [result minimum] is the number of results the search should try to return, where 10 is the default when not specified. The search is done by putting all the apps into various priority
  groups, and only the highest-priority groups which result in the minimum desired results will be used. For example, if the search comes up with grouping of 3-highest priority, 
  5-medium priority, and 20-low priority, then a minimum search of 2 will only return the highest priority group, a minimum search of 4 will return the highest and medium priority
  groups, and a minimum of 9+ will result in all the groups being returned. 

**Request**

.. code-block:: json

 {
 "namespace" : "rpc",
 "name" : "sysadm",
 "id" : "someUniqueID",
 "args" : ["pbi search \"thun\" ", "pbi search \"thun\" text", "pkg search \"thun\""]
 }

**Response**

.. code-block:: json

  {
    "args": {
        "pbi search \"thun\" ": [
            "x11-fm/thunar",
            "mail/thunderbird",
            "www/thundercache",
            "www/thundersnarf",
            "x11/alltray",
            "deskutils/gbirthday",
            "audio/gtkpod",
            "www/libxul"
        ],
        "pbi search \"thun\" text": "www/thundersnarf",
        "pkg search \"thun\"": " "
    },
    "id": "someUniqueID",
    "name": "response",
    "namespace": "rpc"
  }
