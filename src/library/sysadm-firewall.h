//===========================================
//  PC-BSD source code
//  Copyright (c) 2015, PC-BSD Software/iXsystems
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details

#ifndef PORTLOOKUP_H
#define PORTLOOKUP_H
#include <QtCore>
namespace sysadm
{
struct PortInfo{
    int Port;
    QString PortType;
    QString Keyword;
    QString Description;
    bool Recommended;
};

const static int recommendedPorts[] = {22, 80};
const static int recommendedPortsSize = 2;
class Firewall
{

public:
    ///#section: port commands
    /**
     * @description Returns a structure containing information about the port
     * including its port type, keyword, description, and whether it's a
     * recommended port
     *
     * @param portNumber a port number between 0 and 2^16 - 1
     * @param portType specify whether the port is tdp, udp, etc
     *
     * @ErrorConditions Port Number is set to -1 and a description of the error is stored in the description variable
     */
    PortInfo LookUpPort(int portNumber, QString portType);
    /**
     * @brief Opens a port
     * @param portNumber a port number between 0 and 2^16 -1
     * @param portType specify whether the port is tdp, udp, etc
     */
    void OpenPort(int portNumber, QString portType);

    /**
     * @brief ClosePort closes a port
     * @param portNumber a port number between 0 and 2^16 -1
     * @param portType specify whether the port is tdp, udp, etc
     */
    void ClosePort(int portNumber, QString portType);

    /**
     * @brief finds a list of ports that are open gets the info about them
     * and returns them
     * @return a QVector of the open ports
     */
    QVector<PortInfo> OpenPorts();

    ///#endsection

    ///#section: firewall commands
    /**
     * @brief Checks to see if the firewall is running
     * @return true if the firewall is running, false if not
     */
    bool IsRunning();
    /**
     * @brief Starts the firewall
     */
    void Start();
    /**
     * @brief Stops the firewall
     */
    void Stop();
    /**
     * @brief Restarts the firewall
     */
    void Restart();
    ///#endsection

    ///#section: ctors dtors
    Firewall();
    ~Firewall();
    ///#endsection

private:
    void readServicesFile();
    QStringList* portStrings;

    QStringList openports;

    void LoadOpenPorts();
    void SaveOpenPorts();
};
}
#endif // PORTLOOKUP_H
 
