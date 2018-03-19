#include <QGraphicsView>
#include "mainwindow.h"
#include <QtWidgets>
#include "point.h"
#include "route.h"
#include "buttons.h"
#include <queue>
#include <vector>
#include <Qmap>

#define VIEW_CENTER view->viewport()->rect().center()
#define VIEW_WIDTH  view->viewport()->rect().width()
#define VIEW_HEIGHT view->viewport()->rect().height()
typedef std::pair <double, int> P;
QMap <QString, int> Map;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene, this)),
      m_translateButton(Qt::LeftButton),
      m_zoomDelta(0.1),
      m_translateSpeed(1.0),
      m_bMouseTranslate(true),
      m_scale(1.0){
    setCentralWidget(view);
    resize(1600, 1600);//设置窗口大小
    this->image = new QImage();
    initScene();
    initSceneBackground();
    initItem();
    initRoute();
    view->show();
    initButton();
    initComboBox();
    showAll();
}

MainWindow::~MainWindow(){

}
void MainWindow::initItem() {
    num = 41;
    b[0] = new Point(225, 285, "校医务室");
    b[0]->setToolTip("校医务室:看病打针");
    scene->addItem(b[0]);
    b[1] = new Point(341, 285, "10号公寓");
    b[1]->setToolTip("10号公寓:最西北角的公寓");
    scene->addItem(b[1]);
    b[2] = new Point(407, 285, "篮球场");
    b[2]->setToolTip("篮球场：持卡入内");
    scene->addItem(b[2]);
    b[3] = new Point(517, 285, "体育场");
    b[3]->setToolTip("体育场：健身设备齐全");
    scene->addItem(b[3]);
    b[4] = new Point(670, 285, "网球场");
    b[4]->setToolTip("网球场：20元/小时");
    scene->addItem(b[4]);
    b[5] = new Point(810, 125, "北门");
    scene->addItem(b[5]);
    b[5]->setToolTip("北门");
    b[6] = new Point(332, 352, "11号公寓");
    b[6]->setToolTip("11号公寓");
    scene->addItem(b[6]);
    b[7] = new Point(298, 90, "西北门");
    b[7]->setToolTip("西北门：靠近体育馆");
    scene->addItem(b[7]);
    b[8] = new Point(410, 352, "玉兰餐厅");
    b[8]->setToolTip("玉兰苑：有各种特色菜");
    scene->addItem(b[8]);
    b[9] = new Point(515, 342, "大学生活动中心");
    b[9]->setToolTip("大学生活动中心：丰富多彩的大学生活动");
    scene->addItem(b[9]);
    b[10] = new Point(326, 426, "荟萃广场");
    b[10]->setToolTip("荟萃餐厅:有各种特色菜");
    scene->addItem(b[10]);
    b[11] = new Point(819, 341, "讲堂群");
    b[11]->setToolTip("讲堂群：由东环、西环、东廊、西廊、南堂五个教学楼构成");
    scene->addItem(b[11]);
    b[12] = new Point(991, 341, "小黄山");
    b[12]->setToolTip("小黄山：图书馆二期正在建设中");
    scene->addItem(b[12]);
    b[13] = new Point(203, 531, "沙滩排球场");
    b[13]->setToolTip("沙滩排球场");
    scene->addItem(b[13]);
    b[14] = new Point(310, 532, "荟萃苑");
    b[14]->setToolTip("荟萃餐厅：有各种特色菜");
    scene->addItem(b[14]);
    b[15] = new Point(520, 442, "2号公寓");
    b[15]->setToolTip("2号公寓");
    scene->addItem(b[15]);
    b[16] = new Point(520, 522, "3号公寓");
    b[16]->setToolTip("3号公寓");
    scene->addItem(b[16]);
    b[17] = new Point(408, 528, "9号公寓");
    b[17]->setToolTip("9号公寓");
    scene->addItem(b[17]);
    b[18] = new Point(570, 455, "图书馆");
    b[18]->setToolTip("图书馆：一楼文学书库，二楼社科，三楼科技书库~");
    scene->addItem(b[18]);
    b[19] = new Point(628, 538, "南教楼");
    b[19]->setToolTip("南教楼：教学楼");
    scene->addItem(b[19]);
    b[20] = new Point(623, 706, "创造太阳雕塑");
    b[20]->setToolTip("石大的女神");
    scene->addItem(b[20]);
    b[21] = new Point(623, 736, "文理楼");
    b[21]->setToolTip("文理楼：文学院、理学院，马院，经管学院教职工办公楼");
    scene->addItem(b[21]);
    b[22] = new Point(599, 777, "南门");
    b[22]->setToolTip("南门");
    scene->addItem(b[22]);
    b[23] = new Point(640, 795, "南门右侧拐角");
    scene->addItem(b[23]);
    b[24] = new Point(752, 783, "工科楼E座");
    b[24]->setToolTip("工科E");
    scene->addItem(b[24]);
    b[25] = new Point(752, 537, "南教楼东北侧");
    scene->addItem(b[25]);
    b[26] = new Point(752, 644, "唐岛湾");
    b[26]->setToolTip("唐岛湾餐厅：各种美食");
    scene->addItem(b[26]);
    b[27] = new Point(848, 599, "研究生公寓");
    b[27]->setToolTip("研究生公寓，从南往北依次为一、二、三号公寓");
    scene->addItem(b[27]);
    b[28] = new Point(182, 717, "工科楼D");
    b[28]->setToolTip("工科楼D座");
    scene->addItem(b[28]);
    b[29] = new Point(504, 707, "特种实验楼");
    b[29]->setToolTip("特种实验楼");
    scene->addItem(b[29]);
    b[30] = new Point(192, 635, "学生宿舍篮球场");
    scene->addItem(b[30]);
    b[31] = new Point(285, 633, "打印店");
    scene->addItem(b[31]);
    b[32] = new Point(403, 625, "19号公寓");
    b[32]->setToolTip("19号公寓");
    scene->addItem(b[32]);
    b[33] = new Point(506, 625, "特种楼东北侧拐角");
    scene->addItem(b[33]);
    b[34] = new Point(578, 706, "逸夫楼");
    b[34]->setToolTip("逸夫礼堂");
    scene->addItem(b[34]);
    b[35] = new Point(872, 472, "三岔口");
    b[35]->setToolTip("暂无其他信息");
    scene->addItem(b[35]);
    b[36] = new Point(343, 156, "西北门点1");
    scene->addItem(b[36]);
    b[37] = new Point(331, 216, "西北门点2");
    scene->addItem(b[37]);
    b[38] = new Point(675, 339, "基础实验楼C");
    b[38]->setToolTip("基础实验楼C");
    scene->addItem(b[38]);
    b[39] = new Point(628, 389, "多媒体中心");
    b[39]->setToolTip("多媒体中心");
    scene->addItem(b[39]);
    b[40] = new Point(677, 387, "多媒体中心东侧");
    scene->addItem(b[40]);

}

void MainWindow::adjustViewSize() {
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}

void MainWindow::initScene() {
    scene->setSceneRect(0, 0, 1600, 1600);
}

void MainWindow::initSceneBackground() {
    QPixmap bg;
    image->load(":/image/map");
    scene->addPixmap(QPixmap::fromImage(*image));
}

double MainWindow::getLength(int u, int v) {
    qreal xx = b[u]->x() - b[v]->x();
    qreal yy = b[u]->y() - b[v]->y();
    return sqrt(xx*xx + yy*yy);
}

void MainWindow::initRoute() {
    for(int i = 0; i < MAXN; i++) {
        G[i].clear();
    }
    addRoute(0, 1);
    addRoute(0, 13);
    addRoute(1, 2);
    addRoute(1, 6);
    addRoute(2, 3);
    addRoute(3, 4);
    addRoute(2, 8);
    addRoute(3, 9);
    addRoute(4, 5);
    addRoute(5, 12);
    addRoute(6, 8);
    addRoute(6, 10);
    addRoute(8, 9);
    addRoute(7, 36);
    addRoute(36, 37);
    addRoute(0, 37);
    addRoute(8, 17);
    addRoute(9, 15);
    addRoute(9, 38);
    addRoute(11, 38);
    addRoute(10, 14);
    addRoute(11, 12);
    addRoute(12, 35);
    addRoute(13, 30);
    addRoute(13, 14);
    addRoute(14, 17);
    addRoute(15, 16);
    addRoute(15, 18);
    addRoute(16, 17);
    addRoute(16, 19);
    addRoute(16, 33);
    addRoute(17, 32);
    addRoute(18, 19);
    addRoute(19, 20);
    addRoute(19, 25);
    addRoute(20, 21);
    addRoute(20, 34);
    addRoute(21, 22);
    addRoute(21, 23);
    addRoute(21, 34);
    addRoute(22, 23);
    addRoute(22, 34);
    addRoute(23, 24);
    addRoute(24, 26);
    addRoute(26, 25);
    addRoute(25, 27);
    addRoute(25, 35);
    addRoute(27, 25);
    addRoute(28, 29);
    addRoute(28, 30);
    addRoute(29, 33);
    addRoute(30, 31);
    addRoute(31, 32);
    addRoute(32, 33);
    addRoute(4, 38);
    addRoute(39, 19);
    addRoute(39, 40);
    addRoute(40, 38);
    addRoute(27, 35);
    addRoute(20, 29);
    addRoute(14, 31);
}
void MainWindow::addRoute(int u, int v) {
    double length = getLength(u, v);
    G[u].push_back(Route(v, length));
    G[v].push_back(Route(u, length));
}
void MainWindow::slove(int start, int end) {
    scene->addEllipse(b[start]->x()-5, b[start]->y()-5, 10, 10, QPen(Qt::green, 4));
    scene->addEllipse(b[end]->x()-5, b[end]->y()-5, 10, 10, QPen(Qt::red, 4));
    dijstra(start);
    for(int i = end; i != start; i = pre[i]) {
       sleep(2000);
        scene->addLine(b[i]->x(),
                    b[i]->y(),
                       b[pre[i]]->x(),
                    b[pre[i]]->y(),
                     QPen(Qt::black, 4)
                      );
    }
}
void MainWindow:: sleep(unsigned int msec)
    {
        QTime dieTime = QTime::currentTime().addMSecs(msec);
        while( QTime::currentTime() < dieTime )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }



void MainWindow::dijstra(int start) {
    for(int i = 0; i < MAXN; i++) d[i] = INF;
    d[start] = 0;
    std::priority_queue<P, std::vector<P>, std::greater<P> >que;
    que.push(P(0, start));
    while(!que.empty()) {
       P p = que.top();
       int u = p.second;
       que.pop();
       if(p.first > d[u]) continue;
       for(int i = 0; i < (int)G[u].size(); i++) {
           int v = G[u][i].getTo();
           double length = G[u][i].getLength();
           if(d[v] > d[u] + length) {
               d[v] = d[u] + length;
               que.push(P(d[v], v));
               pre[v] = u;
           }
       }
    }
}

void MainWindow ::  initButton() {
    checkbutton = new QPushButton(this);
    checkbutton->setGeometry(QRect(1400, 400, 120, 60));
    checkbutton->setText("查询最短路");
    connect(checkbutton, SIGNAL(clicked()), this, SLOT(deal()));
    changebutton = new QPushButton(this);
    changebutton->setGeometry(QRect(1400, 550, 120, 60));
    changebutton->setText("更改路径长度");
    connect(changebutton, SIGNAL(clicked()), this, SLOT(readLength()));
    resetbutton = new QPushButton(this);
    resetbutton->setGeometry(QRect(1400, 700, 120, 60));
    resetbutton->setText("显示所有路径");
    connect(resetbutton, SIGNAL(clicked()), this, SLOT(showAllWays()));
}
void MainWindow :: initComboBox() {
     startlabel = new QLabel("目的地", this);
     startlabel->setGeometry(QRect(1300, 300, 80, 40));
     endlabel = new QLabel("出发地", this);
     endlabel->setGeometry(QRect(1300, 100, 80, 40));
     endbox = new QComboBox(this);
     endbox->setGeometry(QRect(1400, 100, 150, 40));
     startbox = new QComboBox(this);
     startbox->setGeometry(QRect(1400, 300, 150, 40));
    for(int i = 0; i < num; i++) {
         endbox->addItem(b[i]->getName());
         startbox->addItem(b[i]->getName());
     }
}

void MainWindow :: deal() {
    initSceneBackground();
    initScene();
    slove(startbox->currentIndex(), endbox->currentIndex());
}

void MainWindow :: changeTheLength(double length) {
    int start = startbox->currentIndex();
    int end = endbox->currentIndex();
    int flag = 0;
    for(int i = 0; i < (int)G[start].size(); i++) {
        if(G[start][i].getTo() == end) {
            flag = 1;
            G[start][i].changeLength(length);
        }
    }
    if(!flag) addRoute(start, end);
    else {
        for(int i = 0; i < (int)G[end].size(); i++) {
            if(G[end][i].getTo() == start) {
                G[end][i].changeLength(length);
            }
        }
    }
}

void MainWindow::setTranslateSpeed(qreal speed){
    // 建议速度范围
    Q_ASSERT_X(speed >= 0.0 && speed <= 2.0,
               "InteractiveView::setTranslateSpeed", "Speed should be in range [0.0, 2.0].");
    m_translateSpeed = speed;
}

qreal MainWindow::translateSpeed() const{
    return m_translateSpeed;
}

// 缩放的增量
void MainWindow::setZoomDelta  (qreal delta){
    // 建议增量范围
    Q_ASSERT_X(delta >= 0.0 && delta <= 1.0,
               "InteractiveView::setZoomDelta", "Delta should be in range [0.0, 1.0].");
    m_zoomDelta = delta;
}

qreal MainWindow::zoomDelta() const{
    return m_zoomDelta;
}

// 上/下/左/右键向各个方向移动、加/减键进行缩放、空格/回车键旋转
void MainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_Up:
        translate(QPointF(0, -2));  // 上移
        break;
    case Qt::Key_Down:
        translate(QPointF(0, 2));  // 下移
        break;
    case Qt::Key_Left:
        translate(QPointF(-2, 0));  // 左移
        break;
    case Qt::Key_Right:
        translate(QPointF(2, 0));  // 右移
        break;
    }
}

// 平移
void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (m_bMouseTranslate){
        QPointF mouseDelta = view->mapToScene(event->pos()) - view->mapToScene(m_lastMousePos);
        translate(mouseDelta);
    }
    m_lastMousePos = event->pos();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    qDebug() << event->x();
    qDebug() << event->y();
    if (event->button() == m_translateButton) {
        // 当光标底下没有 item 时，才能移动
        QPointF point = view->mapToScene(event->pos());
        if (scene->itemAt(point, view->transform()) == NULL)  {
            m_bMouseTranslate = true;
            m_lastMousePos = event->pos();
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == m_translateButton)
        m_bMouseTranslate = false;
}

// 放大/缩小
void MainWindow::wheelEvent(QWheelEvent *event){
    // 滚轮的滚动量
    QPoint scrollAmount = event->angleDelta();
    // 正值表示滚轮远离使用者（放大），负值表示朝向使用者（缩小）
    scrollAmount.y() > 0 ? zoomIn() : zoomOut();
}

// 放大
void MainWindow::zoomIn() {
    zoom(1 + m_zoomDelta);
}

// 缩小
void MainWindow::zoomOut() {
    zoom(1 - m_zoomDelta);
}

// 缩放 - scaleFactor：缩放的比例因子
void MainWindow::zoom(float scaleFactor) {
    // 防止过小或过大
    qreal factor = view->transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;
    view->scale(scaleFactor, scaleFactor);
    m_scale *= scaleFactor;
}

// 平移
void MainWindow::translate(QPointF delta) {
    // 根据当前 zoom 缩放平移数
    delta *= m_scale;
    delta *= m_translateSpeed;
    // view 根据鼠标下的点作为锚点来定位 scene
    view->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    QPoint newCenter(VIEW_WIDTH / 2 - delta.x(),  VIEW_HEIGHT / 2 - delta.y());
    view->centerOn(view->mapToScene(newCenter));

    // scene 在 view 的中心点作为锚点
    view->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
}

void MainWindow::readLength() {
    bool isOk;
    QString text = QInputDialog::getText(NULL,
                                          "提示",
                                         "请输入路径的长度",
                                         QLineEdit::Normal,
                                         "10", &isOk);
    if(text.toDouble() < 0) isOk = false;
    if(isOk) {
       QMessageBox::information(NULL,
                                "Information",
                                "输入完成",
                                QMessageBox::Yes|QMessageBox::No,
                                QMessageBox::Yes);
    }
    changeTheLength(text.toDouble());
}
void MainWindow::initView() {
       view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
       view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
       view->setCursor(Qt::PointingHandCursor);
       view->setRenderHint(QPainter::Antialiasing);
       view->setSceneRect(INT_MIN/2, INT_MIN/2, INT_MAX, INT_MAX);
}
void MainWindow::showAll() {
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < (int)G[i].size(); j++) {
            if(G[i][j].getTo() > i) {
                qreal x1 = b[i]->x(), y1 = b[i]->y();
                qreal x2 = b[G[i][j].getTo()]->x();
                qreal y2 = b[G[i][j].getTo()]->y();
                QPen pen(Qt::black, 3);
                scene->addLine(x1+5, y1+5, x2+5, y2+5, pen);
                int length = G[i][j].getLength();
                QGraphicsTextItem *txtitem = new QGraphicsTextItem(QString::number(length, 10));
                txtitem->setPos(QPointF((x1+x2)/2, (y1+y2)/2));
                scene->addItem(txtitem);//添加item到scene上
            }
        }
    }
}

void MainWindow::showAllWays() {
    initSceneBackground();
    initScene();
    initPoint();
    showAll();
}

void MainWindow::initPoint() {
    for(int i = 0; i < num; i++) {
        scene->addEllipse(b[i]->x()+2, b[i]->y()+2, 5, 5, QPen(Qt::red, 4), QBrush(Qt::red));
    }
}
