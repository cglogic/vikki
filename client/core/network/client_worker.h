/*

The MIT License (MIT)

Copyright (c) 2016 Ievgen Polyvanyi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef VIKKI_CLIENT_WORKER_H
#define VIKKI_CLIENT_WORKER_H

#include <QString>
#include <QSslKey>
#include <QSslCertificate>
#include <QSslConfiguration>
#include <QSharedPointer>

#include "network_worker.h"

namespace Vikki
{
	class ClientWorker
		: public NetworkWorker
	{
		Q_OBJECT
		Q_DISABLE_COPY(ClientWorker)

	public:
		ClientWorker();
		~ClientWorker() Q_DECL_OVERRIDE;

	public slots:
		void setConnectionOptions(const QString& hostName, const quint16 port);

		void connect();
		void disconnect();

	private:
		QString mHostName;
		quint16 mPort;

	};

	using ClientWorkerPointer = QSharedPointer<ClientWorker>;
}

#endif // VIKKI_CLIENT_WORKER_H
