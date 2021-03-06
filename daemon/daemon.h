#ifndef HB_H
#define HB_H

#include <QtWidgets/QApplication>
#include <QtWebKit>
#include <QWebFrame>
#include <QWebView>
#include <QWebInspector>

#include "nam.h"

class Daemon : public QWebPage {
    Q_OBJECT

    public:
        Daemon();
        void _load(QUrl url);
        Q_INVOKABLE void genSnapshot(int result);

    private:
        int results;
        NAM *nam;
        QWebPage *wp;
        QTimer *timer;

    signals:
        void newSnapshot(QString html_snapshot);

    public slots:
        void _loadFinished(bool ok);
        bool shouldInterruptJavaScript();

    private slots:
        void createJSMonitor();

    protected:
        void javaScriptConsoleMessage(const QString &message, int lineNumber,const QString &sourceID);

};

#endif // HB_H
