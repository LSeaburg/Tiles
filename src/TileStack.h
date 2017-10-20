/* Logan Seaburg
 *
 * I added a pointer that points to the top block in the pattern to keep
 * track of the stack of the tile.
 */

#ifndef _tilestack_h
#define _tilestack_h

#include <iostream>
#include <string>
#include "gobjects.h"
#include "gwindow.h"
#include "TileNode.h"
using namespace std;

class TileStack {
public:
    TileStack();
    ~TileStack();
    void pushTile(int x, int y, int width, int height, string color);
    void drawAll(GWindow& window) const;
    void highlight(int x, int y);
    void raise(int x, int y);
    void remove(int x, int y);
    void clear();

private:
    TileNode* front;
};

#endif
