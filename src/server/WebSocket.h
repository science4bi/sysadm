// ===============================
//  PC-BSD REST/JSON API Server
// Available under the 3-clause BSD License
// Written by: Ken Moore <ken@pcbsd.org> July 2015
// =================================
#ifndef _PCBSD_REST_WEB_SOCKET_H
#define _PCBSD_REST_WEB_SOCKET_H

#include "globals.h"

#include "RestStructs.h"
#include "AuthorizationManager.h"

class WebSocket : public QObject{
	Q_OBJECT
public:
	WebSocket(QWebSocket*, QString ID, AuthorizationManager *auth);
	WebSocket(QSslSocket*, QString ID, AuthorizationManager *auth);
	~WebSocket();

	QString ID();

private:
	QTimer *idletimer;
	QWebSocket *SOCKET;
	QSslSocket *TSOCKET;
	QString SockID, SockAuthToken, SockPeerIP;
	AuthorizationManager *AUTHSYSTEM;
	QList<EventWatcher::EVENT_TYPE> ForwardEvents;

	void sendReply(QString msg);

	//Main connection comminucations procedure
	void EvaluateREST(QString); //Text -> Rest/JSON struct
	void EvaluateRequest(const RestInputStruct&); // Parse Rest/JSON (does auth/events)

	//Simplification functions
	QString JsonValueToString(QJsonValue);
	QStringList JsonArrayToStringList(QJsonArray);

	//Backend request/reply functions (contained in WebBackend.cpp)
	// -- Subsystem listing routine
	RestOutputStruct::ExitCode AvailableSubsystems(bool fullaccess, QJsonObject *out);
	// -- Main subsystem parser
	RestOutputStruct::ExitCode EvaluateBackendRequest(const RestInputStruct&, QJsonObject *out);


	// -- Individual subsystems
	// -- Server Settings Modification API
	RestOutputStruct::ExitCode EvaluateSysadmSettingsRequest(const QJsonValue in_args, QJsonObject *out);
	// -- rpc syscache API
	RestOutputStruct::ExitCode EvaluateSyscacheRequest(const QJsonValue in_args, QJsonObject *out);
	// -- rpc dispatcher API
	RestOutputStruct::ExitCode EvaluateDispatcherRequest(bool allaccess, const QJsonValue in_args, QJsonObject *out);
	// -- sysadm beadm API
	RestOutputStruct::ExitCode EvaluateSysadmBEADMRequest(const QJsonValue in_args, QJsonObject *out);
	// -- sysadm iocage API
	RestOutputStruct::ExitCode EvaluateSysadmIocageRequest(const QJsonValue in_args, QJsonObject *out);
	// -- sysadm iohyve API
	RestOutputStruct::ExitCode EvaluateSysadmIohyveRequest(const QJsonValue in_args, QJsonObject *out);
	// -- sysadm Network API
	RestOutputStruct::ExitCode EvaluateSysadmNetworkRequest(const QJsonValue in_args, QJsonObject *out);
	// -- sysadm LifePreserver API
	RestOutputStruct::ExitCode EvaluateSysadmLifePreserverRequest(const QJsonValue in_args, QJsonObject *out);
	// -- sysadm info API
	RestOutputStruct::ExitCode EvaluateSysadmSystemMgmtRequest(const QJsonValue in_args, QJsonObject *out);
	// -- sysadm Update API
	RestOutputStruct::ExitCode EvaluateSysadmUpdateRequest(const QJsonValue in_args, QJsonObject *out);
	
private slots:
	void checkIdle(); //see if the currently-connected client is idle
	void SocketClosing();

	//Currently connected socket signal/slot connections
	void EvaluateMessage(const QByteArray&); 
	void EvaluateMessage(const QString&);
	void EvaluateTcpMessage();

	//SSL signal handling
	void nowEncrypted(); //the socket/connection is now encrypted
	void peerError(const QSslError&); //peerVerifyError() signal
	void SslError(const QList<QSslError>&); //sslErrors() signal
	
public slots:
	void EventUpdate(EventWatcher::EVENT_TYPE, QJsonValue = QJsonValue() );

signals:
	void SocketClosed(QString); //ID
};

#endif
