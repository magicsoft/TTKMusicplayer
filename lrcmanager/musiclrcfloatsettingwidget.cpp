#include "musiclrcfloatsettingwidget.h"
#include "musiclrccontainerforinline.h"
#include <QTimer>
#include <QGridLayout>
#include <QPushButton>

MusicLrcFloatSettingWidget::MusicLrcFloatSettingWidget(QWidget *parent)
    : MusicLrcFloatAbstractWidget(parent)
{
    m_rectIn = QRect(355, 120, 165, 210);
    m_rectOut = QRect(515, 171, 165, 105);
    setGeometry(m_rectOut);
    setObjectName("MusicLrcFloatSettingWidget");
    setStyleSheet("#MusicLrcFloatSettingWidget{background:rgba(0, 0, 0, 50);}"
                  "QPushButton{background:transparent;border:none;color:white;font-size:15px;}"
                  "QPushButton::hover{image:url(:/lrc/shadow);}");

    const QString labelStyle = "color:white;image:url(:/lrc/shadow);text-align:center;";
    QLabel *colorLabel = new QLabel(tr("Color"), this);
    QLabel *sizeLabel = new QLabel(tr("Size"), this);
    QLabel *bgLabel = new QLabel(tr("Background"), this);
    colorLabel->setStyleSheet( labelStyle );
    sizeLabel->setStyleSheet( labelStyle );
    bgLabel->setStyleSheet( labelStyle );
    colorLabel->setAlignment(Qt::AlignCenter);
    sizeLabel->setAlignment(Qt::AlignCenter);
    bgLabel->setAlignment(Qt::AlignCenter);
    QFrame *line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);

    QGridLayout *gridLayout = new QGridLayout(this);
    QWidget* colorWidget = new QWidget(this);
    QGridLayout *colorLayout = new QGridLayout(colorWidget);
    colorLayout->setMargin(0);
    colorLayout->setSpacing(1);
    QPushButton *originButton = new QPushButton(colorWidget);
    QPushButton *redButton = new QPushButton(colorWidget);
    QPushButton *orangeButton = new QPushButton(colorWidget);
    QPushButton *yellowButton = new QPushButton(colorWidget);
    QPushButton *greenButton = new QPushButton(colorWidget);
    QPushButton *blueButton = new QPushButton(colorWidget);
    QPushButton *indigoButton = new QPushButton(colorWidget);
    QPushButton *purpleButton = new QPushButton(colorWidget);
    QPushButton *whiteButton = new QPushButton(colorWidget);
    QPushButton *blackButton = new QPushButton(colorWidget);
    originButton->setIcon(QIcon(":/color/origin"));
    redButton->setIcon(QIcon(":/color/red"));
    orangeButton->setIcon(QIcon(":/color/orange"));
    yellowButton->setIcon(QIcon(":/color/yellow"));
    greenButton->setIcon(QIcon(":/color/green"));
    blueButton->setIcon(QIcon(":/color/blue"));
    indigoButton->setIcon(QIcon(":/color/indigo"));
    purpleButton->setIcon(QIcon(":/color/purple"));
    whiteButton->setIcon(QIcon(":/color/white"));
    blackButton->setIcon(QIcon(":/color/black"));
    colorLayout->addWidget(originButton,0,0);
    colorLayout->addWidget(redButton,0,1);
    colorLayout->addWidget(orangeButton,0,2);
    colorLayout->addWidget(yellowButton,0,3);
    colorLayout->addWidget(greenButton,1,0);
    colorLayout->addWidget(blueButton,1,1);
    colorLayout->addWidget(indigoButton,1,2);
    colorLayout->addWidget(purpleButton,1,3);
    colorLayout->addWidget(whiteButton,2,0);
    colorLayout->addWidget(blackButton,2,1);
    originButton->setCursor(QCursor(Qt::PointingHandCursor));
    redButton->setCursor(QCursor(Qt::PointingHandCursor));
    orangeButton->setCursor(QCursor(Qt::PointingHandCursor));
    yellowButton->setCursor(QCursor(Qt::PointingHandCursor));
    greenButton->setCursor(QCursor(Qt::PointingHandCursor));
    blueButton->setCursor(QCursor(Qt::PointingHandCursor));
    indigoButton->setCursor(QCursor(Qt::PointingHandCursor));
    purpleButton->setCursor(QCursor(Qt::PointingHandCursor));
    whiteButton->setCursor(QCursor(Qt::PointingHandCursor));
    blackButton->setCursor(QCursor(Qt::PointingHandCursor));
    connect(originButton,SIGNAL(clicked()), parent ,SLOT(changeCurrentLrcColorOrigin()));
    connect(redButton,SIGNAL(clicked()), parent ,SLOT(changeCurrentLrcColorRed()));
    connect(orangeButton,SIGNAL(clicked()), parent ,SLOT(changeCurrentLrcColorOrange()));
    connect(yellowButton,SIGNAL(clicked()), parent ,SLOT(changeCurrentLrcColorYellow()));
    connect(greenButton,SIGNAL(clicked()), parent ,SLOT(changeCurrentLrcColorGreen()));
    connect(blueButton,SIGNAL(clicked()), parent ,SLOT(changeCurrentLrcColorBlue()));
    connect(indigoButton,SIGNAL(clicked()), parent ,SLOT(changeCurrentLrcColorIndigo()));
    connect(purpleButton,SIGNAL(clicked()), parent ,SLOT(changeCurrentLrcColorPurple()));
    connect(whiteButton,SIGNAL(clicked()), parent ,SLOT(changeCurrentLrcColorWhite()));
    connect(blackButton,SIGNAL(clicked()), parent ,SLOT(changeCurrentLrcColorBlack()));

    QWidget* sizeWidget = new QWidget(this);
    QHBoxLayout *sizeLayout = new QHBoxLayout(sizeWidget);
    QPushButton *sizeBigerButton = new QPushButton(sizeWidget);
    QPushButton *sizeSmallerButton = new QPushButton(sizeWidget);
    sizeBigerButton->setIcon(QIcon(":/desktopTool/lrcsizeUp"));
    sizeSmallerButton->setIcon(QIcon(":/desktopTool/lrcsizeDown"));
    sizeBigerButton->setIconSize(QSize(25,25));
    sizeSmallerButton->setIconSize(QSize(25,25));
    sizeLayout->addWidget(sizeBigerButton);
    sizeLayout->addWidget(sizeSmallerButton);
    sizeBigerButton->setCursor(QCursor(Qt::PointingHandCursor));
    sizeSmallerButton->setCursor(QCursor(Qt::PointingHandCursor));
    connect(sizeBigerButton,SIGNAL(clicked()),SLOT(lrcSizeUpChanged()));
    connect(sizeSmallerButton,SIGNAL(clicked()),SLOT(lrcSizeLowChanged()));

    QPushButton *musicBgButton = new QPushButton(tr("MusicBg"),this);
    musicBgButton->setCursor(QCursor(Qt::PointingHandCursor));
    connect(musicBgButton,SIGNAL(clicked()), SLOT(lrcMusicBackgroundChanged()));
    QPushButton *artBgButton = new QPushButton(tr("ArtBg"),this);
    artBgButton->setCursor(QCursor(Qt::PointingHandCursor));
    connect(artBgButton,SIGNAL(clicked()), SLOT(lrcArtBackgroundChanged()));
    musicBgButton->setStyleSheet(MusicObject::MusicSettingSubmitButton);
    artBgButton->setStyleSheet(MusicObject::MusicSettingSubmitButton);

    QPushButton *settingButton = new QPushButton(tr("More"),this);
    settingButton->setCursor(QCursor(Qt::PointingHandCursor));
    connect(settingButton,SIGNAL(clicked()), parent, SIGNAL(changeCurrentLrcColorSetting()));
    settingButton->setStyleSheet(MusicObject::MusicSettingSubmitButton);

    gridLayout->addWidget(colorLabel,0,0);
    gridLayout->addWidget(colorWidget,0,1);
    gridLayout->addWidget(sizeLabel,1,0);
    gridLayout->addWidget(sizeWidget,1,1);
    gridLayout->addWidget(bgLabel,2,0);
    gridLayout->addWidget(musicBgButton,3,0);
    gridLayout->addWidget(artBgButton,3,1);
    gridLayout->addWidget(line,4,0,1,0);
    gridLayout->addWidget(settingButton,5,0,1,0);
}

void MusicLrcFloatSettingWidget::lrcSizeUpChanged()
{
    MusicLrcContainerForInline* line = static_cast<MusicLrcContainerForInline*>( parent() );
    line->setLrcSize(static_cast<LrcSizeTable>(line->getLrcSize() + 1));
}

void MusicLrcFloatSettingWidget::lrcSizeLowChanged()
{
    MusicLrcContainerForInline* line = static_cast<MusicLrcContainerForInline*>( parent() );
    line->setLrcSize(static_cast<LrcSizeTable>(line->getLrcSize() - 1));
}

void MusicLrcFloatSettingWidget::lrcMusicBackgroundChanged()
{
    MusicLrcContainerForInline* line = static_cast<MusicLrcContainerForInline*>( parent() );
    if(line->artBackgroundIsShow())
    {
        line->theArtBgChanged();
    }
}

void MusicLrcFloatSettingWidget::lrcArtBackgroundChanged()
{
    MusicLrcContainerForInline* line = static_cast<MusicLrcContainerForInline*>( parent() );
    if(!line->artBackgroundIsShow())
    {
        line->theArtBgChanged();
    }
}

void MusicLrcFloatSettingWidget::show()
{
    MusicLrcFloatAbstractWidget::show();
    animationIn();
}

void MusicLrcFloatSettingWidget::leaveEvent(QEvent *)
{
    animationOut();
    QTimer::singleShot(m_animation->duration(), this, SIGNAL(widgetClose()));
}
