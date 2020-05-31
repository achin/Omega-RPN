#include "rpn_selectable_table_view.h"

namespace Rpn {

RpnSelectableTableView::RpnSelectableTableView(Responder * parentResponder, TableViewDataSource * dataSource,
 SelectableTableViewDataSource * selectionDataSource, SelectableTableViewDelegate * delegate) :
  ::SelectableTableView(parentResponder, dataSource, selectionDataSource, delegate)
{
  setVerticalCellOverlap(0);
  setMargins(0);
  setDecoratorType(ScrollView::Decorator::Type::None);
}

void RpnSelectableTableView::scrollToCell(int i, int j) {
  ::SelectableTableView::scrollToCell(i, j);
  if (m_contentView.bounds().height() < bounds().height()) {
    setTopMargin(bounds().height() - m_contentView.bounds().height());
  } else {
    setTopMargin(0);
  }
  ScrollView::layoutSubviews();
  if (m_contentView.bounds().height() - contentOffset().y() < bounds().height()) {
    KDCoordinate contentOffsetX = contentOffset().x();
    KDCoordinate contentOffsetY = dataSource()->cumulatedHeightFromIndex(dataSource()->numberOfRows()) - maxContentHeightDisplayableWithoutScrolling();
    setContentOffset(KDPoint(contentOffsetX, contentOffsetY));
  }
}

}
