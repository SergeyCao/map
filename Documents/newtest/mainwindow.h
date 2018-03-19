#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "point.h"
#include <QMainWindow>

#include <route.h>
#include <vector>
class QGraphicsScene;
class QGraphicsView;
class QGraphicsItem;
const int MAXN = 50;
const int INF = 1e9;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void adjustViewSize();
    void showAllWays();
private:
    void initScene();
    void initSceneBackground();
    void initItem();
    void initRoute();
    void initButton();
    void initComboBox();
    void initPoint();
    void showAll();
    void sleep(unsigned int msec);
    void addRoute(int from, int to);
    double getLength(int from, int to);
    void dijstra(int start);
    void slove(int start, int end);
    void changeTheLength(double length);
    void initView();
    QGraphicsScene *scene;
    QGraphicsView *view;
    QPushButton *checkbutton;
    QPushButton *changebutton;
    QPushButton *resetbutton;
    QComboBox *startbox, *endbox;
    QLabel *startlabel, *endlabel;
    Point *b[MAXN];
    std::vector <Route> G[MAXN];
    QImage *image;
    double d[MAXN];
    int pre[MAXN];
    int start, end;
    int num;

private slots:
    void deal();
    void readLength();
    //void fuck(qreal x1, qreal y1, qreal x2, qreal y2);
private:
    //平移的增量
    void setTranslateSpeed(qreal speed);
    qreal translateSpeed() const;

    // 缩放的增量
    void setZoomDelta(qreal delta);
    qreal zoomDelta() const;

protected:
    // 上/下/左/右键向各个方向移动、加/减键进行缩放、空格/回车键旋转
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    // 平移
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    // 放大/缩小
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
    //void timerEvent(QTimerEvent *);
public Q_SLOTS:
    void zoomIn();  // 放大
    void zoomOut();  // 缩小
    void zoom(float scaleFactor); // 缩放 - scaleFactor：缩放的比例因子
    void translate(QPointF delta);  // 平移

private:
    Qt::MouseButton m_translateButton;  // 平移按钮
    qreal m_translateSpeed;  // 平移速度
    qreal m_zoomDelta;  // 缩放的增量
    bool m_bMouseTranslate;  // 平移标识
    QPoint m_lastMousePos;  // 鼠标最后按下的位置
    qreal m_scale;  // 缩放值
};

#endif // MAINWINDOW_H
