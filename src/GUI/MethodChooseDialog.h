#ifndef METHODCHOOSEDIALOG_H
#define	METHODCHOOSEDIALOG_H

#include <QDialog>
#include "ui_MethodChooseDialog.h"

/**
 * This is Qt Dialog to choose the visualization methods. It is handled by MethodCreator.
 */
class MethodChooseDialog : public QDialog, public Ui::Dialog {
    Q_OBJECT
    
    public:
        MethodChooseDialog(const QMap<QString, int> &data, QWidget *parent = 0);
        ~MethodChooseDialog();
             
};

#endif	/* METHODCHOOSEDIALOG_H */

