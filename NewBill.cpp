#include "NewBill.h"
#include <QLabel>
#include <QLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <QIcon>
#include <QAction>
#include <QFileDialog>
#include <QDialogButtonBox>

/*** NewBill ***/
NewBill::NewBill(const QString &filename)
{
    QLabel *image;
    QDialogButtonBox *buttonBox;


    /*** Main Layout ***/
    QHBoxLayout *mainLayout = new QHBoxLayout;
    {
        /** Image on the left **/
        image = new QLabel;
        mainLayout->addWidget(image);

        /** Input layout **/
        QVBoxLayout *buttonLayout = new QVBoxLayout;
        {
            QFormLayout *inputLayout = new QFormLayout;
            {
                m_Input.file = new QLineEdit;
                m_Input.file->setReadOnly(true);
                inputLayout->addRow(tr("Fichier de la &facture:"), m_Input.file);

                m_Input.date = new QDateEdit(QDate::currentDate());
                m_Input.date->setCalendarPopup(true);
                m_Input.date->setDisplayFormat(tr("dd/MM/yyyy"));
                inputLayout->addRow(tr("&Date:"), m_Input.date);

                // TODO: Put category as a special class
                m_Input.category = new QLineEdit;
                inputLayout->addRow(tr("&Catégorie:"), m_Input.category);

                m_Input.value = new QDoubleSpinBox();
                m_Input.value->setRange(0, 10000000000); 
                inputLayout->addRow(tr("&Montant:"), m_Input.value);

                // TODO: Put entity as a special class
                m_Input.entity = new QLineEdit;
                inputLayout->addRow(tr("&Nom:"), m_Input.entity); 
            }
            buttonLayout->addLayout(inputLayout);

            buttonLayout->addStretch();

            buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel); 
            buttonLayout->addWidget(buttonBox);
        }
        mainLayout->addLayout(buttonLayout); 
    }
    setLayout(mainLayout);

    /*** Action behaviour and slot connection ***/
    {
        /** Upload **/
        QIcon uploadIcon = QIcon("upload_icon.png");
        QAction *uploadFile = m_Input.file->addAction(uploadIcon, QLineEdit::ActionPosition::TrailingPosition);
        connect(uploadFile, &QAction::triggered, this, &NewBill::on_uploadingFile);

        /** Image synchronisation **/
        connect(m_Input.file, &QLineEdit::textChanged, image, &QLabel::setPixmap);

        /*** Button press ***/
        connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
        connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    }

    /*** Member initialisation **/
    {
        m_Input.file->setText(filename);
    }
} 

void NewBill::on_uploadingFile(void)
{
    QString fileOpened = QFileDialog::getOpenFileName(this, tr("Ajouter la facture"), "~/", tr("Images (*.png *.bmp *.jpg);;Fichiers quelquonques (*)"));
    if(fileOpened == "")
        return;

    m_Input.file->setText(fileOpened);
}
