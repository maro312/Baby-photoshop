#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstring>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void updateImage();
    void blackWhiteRGB();

    void darken();

    void lighten();

    void detectEdges();

    void blur();

    void flip(bool h, bool v);

    void merge(unsigned char image2[256][256][3]);

    void Shuffle_Image(int quarter[4]);

    void enlargeRGB();

    void rotate90RGB();

    void rotate180RGB();

    void rotate270RGB();

    void mirrorImage(int side);


private slots:
    void on_browse_clicked();

    void on_Invert_button_clicked();

    void invertRGB();

    void on_BW_btn_clicked();

    void on_pushButton_clicked();

    void on_dark_btn_clicked();

    void on_light_btn_clicked();

    void on_detect_ptn_clicked();

    void on_blur_ptn_clicked();

    void on_flip_btn_clicked();

    void on_Apply_btn_clicked();

    void on_merge_btn_clicked();

    void on_Merge_btn_clicked();

    void on_shuff_btn_clicked();

    void on_shuff1_clicked();

    void on_shuff2_clicked();

    void on_shuff3_clicked();

    void on_shuff4_clicked();

    void on_shuffApply_clicked();

    void on_en_btn_clicked();

    void on_en1_clicked();

    void on_en2_clicked();

    void on_en3_clicked();

    void on_en4_clicked();

    void on_rot_90_clicked();

    void on_Rotat_btn_clicked();

    void on_rot_180_clicked();

    void on_rot_270_clicked();

    void on_Apply_rotate_clicked();

    void on_mir_right_clicked();

    void on_mir_left_clicked();

    void on_mir_up_clicked();

    void on_mir_down_clicked();

    void on_apply_miror_clicked();

    void on_Miror_btn_clicked();

    void on_save_btn_clicked();



    void on_clear_btn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
