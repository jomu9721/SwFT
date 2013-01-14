/*
   Copyright 2012 Cameron Tinker

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef EXTENDEDQLABEL_H
#define EXTENDEDQLABEL_H

#include <QLabel>
#include <QtCore/QDebug>

class extendedQlabel : public QLabel
{
    Q_OBJECT
public:
    explicit extendedQlabel( const QString& text ="", QWidget * parent = 0 );
    ~extendedQlabel();

signals:
    void clicked();
    void hover();

public slots:
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
};

#endif // EXTENDEDQLABEL_H
