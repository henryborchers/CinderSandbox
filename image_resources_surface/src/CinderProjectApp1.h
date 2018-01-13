//
// Created by Borchers, Henry Samuel on 1/13/18.
//

#ifndef HELLOCINDER_CINDERPROJECTAPP1_H
#define HELLOCINDER_CINDERPROJECTAPP1_H


class CinderProjectApp : public cinder::app::App {
public:
    void setup() override;
    void mouseDown( cinder::app::MouseEvent event ) override;
    void update() override;
    void draw() override;
};


#endif //HELLOCINDER_CINDERPROJECTAPP1_H
