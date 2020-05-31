#ifndef RPN_SELECTABLE_TABLE_VIEW_H
#define RPN_SELECTABLE_TABLE_VIEW_H

#include <escher.h>

namespace Rpn {

class RpnSelectableTableView : public ::SelectableTableView {
public:
  RpnSelectableTableView(Responder * parentResponder, TableViewDataSource * dataSource,
    SelectableTableViewDataSource * selectionDataSource, SelectableTableViewDelegate * delegate = nullptr);
  void scrollToCell(int i, int j) override;
};

}

#endif
