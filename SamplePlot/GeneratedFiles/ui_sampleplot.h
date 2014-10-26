/********************************************************************************
** Form generated from reading UI file 'sampleplot.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAMPLEPLOT_H
#define UI_SAMPLEPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_SamplePlotClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit_2;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget;
    QLabel *label;
    QTextEdit *textEdit;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidget_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *customPlot;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SamplePlotClass)
    {
        if (SamplePlotClass->objectName().isEmpty())
            SamplePlotClass->setObjectName(QStringLiteral("SamplePlotClass"));
        SamplePlotClass->resize(1557, 846);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SamplePlotClass->sizePolicy().hasHeightForWidth());
        SamplePlotClass->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(SamplePlotClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_5);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(groupBox_5);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));
        pushButton->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_2->addWidget(pushButton);

        plainTextEdit_2 = new QPlainTextEdit(groupBox_5);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextEdit_2->sizePolicy().hasHeightForWidth());
        plainTextEdit_2->setSizePolicy(sizePolicy1);
        plainTextEdit_2->setMinimumSize(QSize(350, 0));
        plainTextEdit_2->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(plainTextEdit_2);

        progressBar = new QProgressBar(groupBox_5);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMinimumSize(QSize(0, 30));
        progressBar->setValue(24);

        horizontalLayout_2->addWidget(progressBar);


        verticalLayout_4->addWidget(groupBox_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(250, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listWidget = new QListWidget(groupBox_2);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setMaximumSize(QSize(16777215, 150));
        textEdit->setReadOnly(true);
        textEdit->setOverwriteMode(true);
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_2->addWidget(textEdit);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(250, 16777215));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        listWidget_2 = new QListWidget(groupBox_3);
        new QListWidgetItem(listWidget_2);
        new QListWidgetItem(listWidget_2);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));

        horizontalLayout_3->addWidget(listWidget_2);


        verticalLayout_3->addWidget(groupBox_3);


        horizontalLayout_4->addLayout(verticalLayout_3);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        customPlot = new QCustomPlot(groupBox);
        customPlot->setObjectName(QStringLiteral("customPlot"));

        horizontalLayout->addWidget(customPlot);


        horizontalLayout_4->addWidget(groupBox);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(300, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(groupBox_4);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit);


        horizontalLayout_4->addWidget(groupBox_4);


        verticalLayout_4->addLayout(horizontalLayout_4);

        SamplePlotClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SamplePlotClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SamplePlotClass->setStatusBar(statusBar);

        retranslateUi(SamplePlotClass);

        QMetaObject::connectSlotsByName(SamplePlotClass);
    } // setupUi

    void retranslateUi(QMainWindow *SamplePlotClass)
    {
        SamplePlotClass->setWindowTitle(QApplication::translate("SamplePlotClass", "SamplePlot", 0));
        groupBox_5->setTitle(QApplication::translate("SamplePlotClass", "Analyze", 0));
        pushButton->setText(QApplication::translate("SamplePlotClass", "Start", 0));
        groupBox_2->setTitle(QApplication::translate("SamplePlotClass", "Available algorithms", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("SamplePlotClass", "Binary Search", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("SamplePlotClass", "Linear Search", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("SamplePlotClass", "QuickFind", 0));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("SamplePlotClass", "QuickUnion", 0));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("SamplePlotClass", "WeightedQuickUnion", 0));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("SamplePlotClass", "3SumBrutForce", 0));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("SamplePlotClass", "3SumSorted", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("SamplePlotClass", "Description", 0));
        groupBox_3->setTitle(QApplication::translate("SamplePlotClass", "Testing algorithms", 0));

        const bool __sortingEnabled1 = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem7 = listWidget_2->item(0);
        ___qlistwidgetitem7->setText(QApplication::translate("SamplePlotClass", "Binary Search", 0));
        QListWidgetItem *___qlistwidgetitem8 = listWidget_2->item(1);
        ___qlistwidgetitem8->setText(QApplication::translate("SamplePlotClass", "Linear Search", 0));
        listWidget_2->setSortingEnabled(__sortingEnabled1);

        groupBox->setTitle(QApplication::translate("SamplePlotClass", "Graph", 0));
        groupBox_4->setTitle(QApplication::translate("SamplePlotClass", "Detailed Results", 0));
#ifndef QT_NO_STATUSTIP
        statusBar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        statusBar->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class SamplePlotClass: public Ui_SamplePlotClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAMPLEPLOT_H
