#ifndef SHOT_H
#define SHOT_H

#include <QPoint>
#include <QDebug>

class ShotsStrategy {
public:
    virtual QPoint shot(QPoint point = QPoint(0, 0)) = 0;
};

class ManualShotStrategy : public ShotsStrategy {
public:
    QPoint shot(QPoint point = QPoint(0, 0)) override;
};

class FullRandomShotStrategy : public ShotsStrategy {
public:
    QPoint shot(QPoint point = QPoint(0, 0)) override;
};

#endif // SHOT_H
