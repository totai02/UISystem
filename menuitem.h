#ifndef MENUITEM_H
#define MENUITEM_H
#include <vector>
#include <string>
#include <functional>
#include "PCD8544.h"

#include "define.h"

using namespace std;

extern int min(int a, int b);

class MenuItem
{
public:
    MenuItem(string title = "");
    MenuItem(string title, string content);
    void addItem(MenuItem *item);
    void clearItem();
    vector<MenuItem *> getItems() const;
    string getTitle();
    void setTitle(string title);
    virtual void draw(int x, int y, bool hover = false);
    virtual void select();
    virtual void exit();
    void setAction(function<void()> cb);
    void setExitAction(function<void()> cb);

    MenuItem* parent;
protected:
    int delayTime = 3;
    int windowPos = 0;
    function<void()> callback = [](){};
    function<void()> exitCb = [](){};
    string title, content;
    vector<MenuItem*> items;
};

#endif // MENUITEM_H
