#include "route.h"
#include <QtWidgets>

Route::Route() {

}

Route::Route(int _to, double _length) {
    to = _to, length = _length;
}

double Route::getLength() {
    return length;
}
int Route::getTo() {
    return to;
}

void Route::changeLength(double _length) {
    length = _length;
}
