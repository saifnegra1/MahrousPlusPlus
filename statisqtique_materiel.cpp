#include "statisqtique_materiel.h"
#include "ui_statisqtique_materiel.h"

Statisqtique_materiel::Statisqtique_materiel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statisqtique_materiel)
{
    ui->setupUi(this);

}

Statisqtique_materiel::~Statisqtique_materiel()
{
    delete ui;
}
int Statisqtique_materiel::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from materiel where PRIXMATERIEL BETWEEN '10' AND '50'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Statisqtique_materiel::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from materiel where PRIXMATERIEL BETWEEN '51' AND '100'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;

}
int Statisqtique_materiel::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from materiel where PRIXMATERIEL BETWEEN '101' AND '99999'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void Statisqtique_materiel::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    //cout<<b<<endl ;
    int c=Statistique_partie3();
   // cout<<c<<endl ;
    int d=Statistique_partie4();
    //cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(50,50,this->width()-500,this->width()-500);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("10-50") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("51-100") ;
    painter.setBrush(Qt::red);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("101-9999") ;

}
