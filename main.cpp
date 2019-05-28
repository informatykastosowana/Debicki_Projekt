#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <list>
#include <iostream>
#include <cstdlib>
#include <string>

const int width = 1200;
const int height = 800;

class Game_time
{
public:
    sf::Sprite sprite0, sprite1, sprite2, sprite3;
    int time_to_end;
    sf::Clock game_time;
    Game_time(sf::Texture &t, int Time_to_end)
    {
        time_to_end = Time_to_end;

        sprite0.setTexture(t);
        sprite0.setScale(0.5, 0.5);
        sprite0.setPosition(990, 10);

        sprite1.setTexture(t);
        sprite1.setScale(0.5, 0.5);
        sprite1.setPosition(1040, 10);

        sprite2.setTexture(t);
        sprite2.setScale(0.5, 0.5);
        sprite2.setPosition(1090, 10);

        sprite3.setTexture(t);
        sprite3.setScale(0.5, 0.5);
        sprite3.setPosition(1140, 10);

        sprite3.setTextureRect(sf::IntRect(100*(time_to_end%10), 100, 100, 100));
        sprite2.setTextureRect(sf::IntRect(100*((time_to_end/10)%10), 100, 100, 100));
        sprite1.setTextureRect(sf::IntRect(100*((time_to_end/100)%10), 100, 100, 100));
        sprite0.setTextureRect(sf::IntRect(100*((time_to_end/1000)%10), 100, 100, 100));
    }

    void update()
    {
        if(game_time.getElapsedTime().asMilliseconds()>1000)
        {
            time_to_end--;
            update_time();
            game_time.restart();
        }
    }

    bool isEnd()
    {
        if(time_to_end < 0)
        {
            return true;
        }
        else return false;
    }

    void update_time()
    {
        sprite3.setTextureRect(sf::IntRect(100*(time_to_end%10), 100, 100, 100));
        sprite2.setTextureRect(sf::IntRect(100*((time_to_end/10)%10), 100, 100, 100));
        sprite1.setTextureRect(sf::IntRect(100*((time_to_end/100)%10), 100, 100, 100));
        sprite0.setTextureRect(sf::IntRect(100*((time_to_end/1000)%10), 100, 100, 100));
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(sprite0);
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite3);
    }

virtual ~Game_time(){};

};

class Score
{
public:
    sf::Sprite sprite0, sprite1, sprite2, sprite3, sprite4, sprite5, sprite6, sprite7;
    int SCORE = 0;
    Score(sf::Texture &t)
    {
        sprite0.setTexture(t);
        sprite0.setScale(0.5, 0.5);
        sprite0.setTextureRect(sf::IntRect(0, 0, 100, 100));
        sprite0.setPosition(10, 10);

        sprite1.setTexture(t);
        sprite1.setScale(0.5, 0.5);
        sprite1.setTextureRect(sf::IntRect(0, 0, 100, 100));
        sprite1.setPosition(60, 10);

        sprite2.setTexture(t);
        sprite2.setScale(0.5, 0.5);
        sprite2.setTextureRect(sf::IntRect(0, 0, 100, 100));
        sprite2.setPosition(110, 10);

        sprite3.setTexture(t);
        sprite3.setScale(0.5, 0.5);
        sprite3.setTextureRect(sf::IntRect(0, 0, 100, 100));
        sprite3.setPosition(160, 10);

        sprite4.setTexture(t);
        sprite4.setScale(0.5, 0.5);
        sprite4.setTextureRect(sf::IntRect(0, 0, 100, 100));
        sprite4.setPosition(210, 10);

        sprite5.setTexture(t);
        sprite5.setScale(0.5, 0.5);
        sprite5.setTextureRect(sf::IntRect(0, 0, 100, 100));
        sprite5.setPosition(260, 10);

        sprite6.setTexture(t);
        sprite6.setScale(0.5, 0.5);
        sprite6.setTextureRect(sf::IntRect(0, 0, 100, 100));
        sprite6.setPosition(310, 10);

        sprite7.setTexture(t);
        sprite7.setScale(0.5, 0.5);
        sprite7.setTextureRect(sf::IntRect(0, 0, 100, 100));
        sprite7.setPosition(360, 10);
    }

    void add_to_score(int number)
    {
        SCORE += number;
        if(SCORE < 0) SCORE = 0;
    }

    void update()
    {
        sprite7.setTextureRect(sf::IntRect(100*(SCORE%10), 100, 100, 100));
        sprite6.setTextureRect(sf::IntRect(100*((SCORE/10)%10), 100, 100, 100));
        sprite5.setTextureRect(sf::IntRect(100*((SCORE/100)%10), 100, 100, 100));
        sprite4.setTextureRect(sf::IntRect(100*((SCORE/1000)%10), 100, 100, 100));
        sprite3.setTextureRect(sf::IntRect(100*((SCORE/10000)%10), 100, 100, 100));
        sprite2.setTextureRect(sf::IntRect(100*((SCORE/100000)%10), 100, 100, 100));
        sprite1.setTextureRect(sf::IntRect(100*((SCORE/1000000)%10), 100, 100, 100));
        sprite0.setTextureRect(sf::IntRect(100*((SCORE/10000000)%10), 100, 100, 100));
    }

    void end_game()
    {
        sprite0.setScale(1, 1);
        sprite1.setScale(1, 1);
        sprite2.setScale(1, 1);
        sprite3.setScale(1, 1);
        sprite4.setScale(1, 1);
        sprite5.setScale(1, 1);
        sprite6.setScale(1, 1);
        sprite7.setScale(1, 1);

        sprite0.setPosition(200, 100);
        sprite1.setPosition(300, 100);
        sprite2.setPosition(400, 100);
        sprite3.setPosition(500, 100);
        sprite4.setPosition(600, 100);
        sprite5.setPosition(700, 100);
        sprite6.setPosition(800, 100);
        sprite7.setPosition(900, 100);

        sprite7.setTextureRect(sf::IntRect(100*(SCORE%10), 200, 100, 100));
        sprite6.setTextureRect(sf::IntRect(100*((SCORE/10)%10), 200, 100, 100));
        sprite5.setTextureRect(sf::IntRect(100*((SCORE/100)%10), 200, 100, 100));
        sprite4.setTextureRect(sf::IntRect(100*((SCORE/1000)%10), 200, 100, 100));
        sprite3.setTextureRect(sf::IntRect(100*((SCORE/10000)%10), 200, 100, 100));
        sprite2.setTextureRect(sf::IntRect(100*((SCORE/100000)%10), 200, 100, 100));
        sprite1.setTextureRect(sf::IntRect(100*((SCORE/1000000)%10), 200, 100, 100));
        sprite0.setTextureRect(sf::IntRect(100*((SCORE/10000000)%10), 200, 100, 100));
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(sprite0);
        window.draw(sprite1);
        window.draw(sprite2);
        window.draw(sprite3);
        window.draw(sprite4);
        window.draw(sprite5);
        window.draw(sprite6);
        window.draw(sprite7);
    }

virtual ~Score(){};

};

class Background
{
public:
    int x_position;
    sf::Sprite bground, bground2;
    Background(sf::Texture &t, sf::Texture &t2)
    {
        x_position = 0;
        bground.setTexture(t);
        bground2.setTexture(t2);
    }

    void update()
    {
        x_position -= 5;
        bground.setPosition(x_position, 0);
        bground2.setPosition(x_position + 2400, 0);
        if(x_position < -2400) x_position=0;
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(bground);
        window.draw(bground2);
    }

};


class Object
{
public:
    sf::Sprite sprite;
    int x,y,w,h;
    int life;
    bool upadek = false;
    std::string name;
    Object(){};


    void settings(sf::Texture &t, int X, int Y, int W, int H)
    {
        x = X;
        y = Y;
        w = W;
        h = H;
        sprite.setTexture(t);
        sprite.setPosition(x, y);
        sprite.setOrigin(w/2, h/2);
    }


    void draw(sf::RenderWindow &window)
    {
        window.draw(sprite);
    }
virtual void init(){};
virtual void update(){};

virtual ~Object(){};
};


class Animation
{
public:
    float Frame, speed;
    sf::Sprite sprite;
    std::string name;
    std::vector<sf::IntRect> frames;
    Animation(sf::Texture &t, std::string Name, int x, int y, int w, int h, int count, float Speed)
    {
        name = Name;
        Frame = 0;
        speed = Speed;
        for (int i=0;i<count;i++)
         frames.push_back(sf::IntRect(x+i*w, y, w, h));

        sprite.setTexture(t);
        sprite.setOrigin(w/2, h/2);
        sprite.setTextureRect(frames[0]);
    }

    void update()
    {
        Frame += speed;
        int n = frames.size();
        if (Frame >= n) Frame -= n;
        if (n > 0) sprite.setTextureRect(frames[int(Frame)]);
    }

    void set_pos(int X, int Y)
    {
        sprite.setPosition(X, Y);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(sprite);
    }

    bool IsEnd()
    {
        return Frame+speed >= frames.size();
    }

virtual ~Animation(){};

};

class Player: public Object
{
public:
    Player()
    {
        life = 1;
        name = "player";
    };

    void update()
    {
        sprite.setPosition(x, y);

    }

    void init()
    {
        sprite.rotate(-90);
    }

};

class Bullet: public Object
{
public:
    Bullet(std::string Name)
    {
        name = Name;
        life = 1;
    };

    void update()
    {
        x += 10;
        sprite.setPosition(x, y);
        if(x > width) life = 0;
    }

};

class Enemy: public Object
{
public:
    Enemy(std::string Name)
    {
        name = Name;
        life = 1;
    }

    void update()
    {
        if(upadek == false)
        {
        x -= 10;
        sprite.setPosition(x, y);

        }
        else if(upadek == true)
        {
        x -= 5;
        y -= 10;
        sprite.setPosition(x, y);
        sprite.setRotation(x);
        if(x < 0 || y > height) life = 0;
        }
    }

};

bool isCollide(Object *a, Object *b)
{
    return a->sprite.getGlobalBounds().intersects(b->sprite.getGlobalBounds());
}



int main()
{
    sf::RenderWindow window( sf::VideoMode(width, height), "Platypus", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);

    /// Settings ///
    srand(time(0));

    int mouse_x = 0;
    int mouse_y = 0;
    int enemy_show = 2000;
    int enemy_choose;
    int time_to_end = 120;
    bool END_GAME = false;

    sf::Clock clock_enemy;
    sf::Clock clock_harder;
    sf::Clock hehe_clock;

    sf::Time time_enemy;
    sf::Time time_harder;
    sf::Time hehe_time;

    /// Music ///
    sf::SoundBuffer buffer;
    sf::Sound sound;

    if (!buffer.loadFromFile("files/music/monster.wav"))
        return -1;

    sound.setBuffer(buffer);
    sound.play();
    /// Textures ///

    sf::Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t11, t12, t13; // Width Height
    sf::Texture t20, t21, t22, t23, t24, t25, t26, t30, t31;
    t1.loadFromFile("files/img/background.png"); // 2400x800
    t2.loadFromFile("files/img/background.png"); // 2400x800
    t3.loadFromFile("files/img/kotlin.png"); // 100x200
    t4.loadFromFile("files/img/redbullet.png"); // 100x60
    t5.loadFromFile("files/img/hand.png"); // 100x60
    t6.loadFromFile("files/img/enemy.png"); // 150x100
    t7.loadFromFile("files/img/burger.png"); // 120x80
    t8.loadFromFile("files/img/frytki.png"); // 90x120
    t9.loadFromFile("files/img/bonus.png"); // 100x100
    t11.loadFromFile("files/img/piwo1.png"); // 40x100
    t12.loadFromFile("files/img/piwo2.png"); // 40x100
    t13.loadFromFile("files/img/piwo3.png"); // 40x100

    t20.loadFromFile("files/animations/explosion.png"); // 200x200 17 frames
    t21.loadFromFile("files/animations/sorry.png"); // 150x150 36 frames
    t22.loadFromFile("files/animations/fire.png"); // 150x150 10 frames
    t23.loadFromFile("files/animations/simpson.png"); // 150x150 8 frames
    t24.loadFromFile("files/animations/happy.png"); // 150x150 4 frames
    t25.loadFromFile("files/animations/sad.png"); // 150x150 18 frames
    t26.loadFromFile("files/animations/star.png"); // 200x200 7 frames

    t30.loadFromFile("files/img/numbers.png");
    t31.loadFromFile("files/animations/end_game.png"); // 400x400 4 frames


    t1.setSmooth(true);
    t2.setSmooth(true);

    /// Inits //
    std::list<Object*> objects;
    std::list<Animation*> animations;

    Game_time *gt = new Game_time(t30, time_to_end);
    hehe_clock.restart();

    END_GAME = gt->isEnd();
    Score *sc = new Score(t30);
    Background *bg = new Background(t1, t2);
    Animation *endgame = new Animation(t31, "end_game", 0, 0, 400, 400, 4, 0.2);
    endgame->set_pos(600, 400);


    Player *p = new Player();
    p->settings(t3, 100, 100, 100, 200);
    p->init();
    objects.push_back(p);


    /// Main Loop ///
    while (window.isOpen())
    {
        /// Events ///
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
            if (event.type == sf::Event::MouseMoved)
            {
                mouse_x = sf::Mouse::getPosition(window).x;
                mouse_y = sf::Mouse::getPosition(window).y;
                p->x = mouse_x;
                p->y = mouse_y;

            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    Bullet *b = new Bullet("redbullet");
                    b->settings(t4, p->x + p->w + 30, p->y, 100, 60);
                    objects.push_back(b);
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    Bullet *bh = new Bullet("handbullet");
                    bh->settings(t5, p->x + p->w + 30, p->y, 100, 60);
                    objects.push_back(bh);
                }
            }
        }
        /// End Events ///


    /// Timer Enemy ///
    time_harder = clock_harder.getElapsedTime();
    if(time_harder.asMilliseconds() > 30000)
    {
        enemy_show -= 500;
        clock_harder.restart();
    }


    time_enemy = clock_enemy.getElapsedTime();
    //std::cout << time_enemy.asSeconds() << std::endl;
    if(time_enemy.asMilliseconds() > enemy_show)
    {
        enemy_choose = rand() % 100;
        //std::cout << enemy_choose << std::endl;
        if(enemy_choose == 0)
        {
            Enemy *e = new Enemy("bonus");
            e->settings(t9, width + 200, rand() % 700 + 100, 100, 100);
            objects.push_back(e);
        }
        else if(enemy_choose >= 1 && enemy_choose < 6)
        {
            Enemy *e = new Enemy("rocket");
            e->settings(t6, width + 200, rand() % 700 + 100, 150, 100);
            e->life = rand() % 5 + 1;
            objects.push_back(e);
        }
        else if(enemy_choose >= 6 && enemy_choose < 10)
        {
            Enemy *e = new Enemy("piwo3");
            e->settings(t13, width + 200, rand() % 700 + 100, 40, 100);
            objects.push_back(e);
        }
        else if(enemy_choose >= 10 && enemy_choose < 25)
        {
            Enemy *e = new Enemy("piwo2");
            e->settings(t12, width + 200, rand() % 700 + 100, 40, 100);
            objects.push_back(e);
        }
        else if(enemy_choose >= 25 && enemy_choose < 35)
        {
            Enemy *e = new Enemy("piwo1");
            e->settings(t11, width + 200, rand() % 700 + 100, 40, 100);
            objects.push_back(e);
        }
        else if(enemy_choose >= 35 && enemy_choose < 75)
        {
            Enemy *e = new Enemy("fries");
            e->settings(t8, width + 200, rand() % 700 + 100, 90, 120);
            objects.push_back(e);
        }
        else if(enemy_choose >= 75 && enemy_choose < 100)
        {
            Enemy *e = new Enemy("burger");
            e->settings(t7, width + 200, rand() % 700 + 100, 120, 80);
            objects.push_back(e);
        }

        clock_enemy.restart();
    }


    /// Collisions ///

    hehe_time = hehe_clock.getElapsedTime();
    if(hehe_time.asSeconds() < 118)
    {
    for(auto a:objects)
    {
        for(auto b:objects)
    {
        int what = rand() % 2;
        if((a->name=="redbullet" && b->name=="burger") || (a->name=="redbullet" && b->name=="fries"))
            if(isCollide(a, b))
        {
            if(b->name=="burger") sc->add_to_score(150);
            if(b->name=="fries") sc->add_to_score(100);
            if(what == 1)
            {
                a->life = 0;
                b->upadek = true;
                b->name = "do_not_touch";
            }
            else
            {
                a->life = 0;
                b->life = 0;
                Animation *anim = new Animation(t22, "fire", 0, 0, 150, 150, 10, 0.3);
                anim->set_pos(b->x, b->y);
                animations.push_back(anim);
            }

        }
        if((a->name=="handbullet" && b->name=="burger") || (a->name=="handbullet" && b->name=="fries"))
            if(isCollide(a, b))
        {
            if(b->name=="burger") sc->add_to_score(-100);
            if(b->name=="fries") sc->add_to_score(-50);
                a->life = 0;
                b->life = 0;
                Animation *anim = new Animation(t21, "sorry", 0, 0, 150, 150, 36, 0.6);
                anim->set_pos(b->x, b->y);
                animations.push_back(anim);
        }
        if((a->name=="redbullet" && b->name=="piwo1") || (a->name=="redbullet" && b->name=="piwo2") || (a->name=="redbullet" && b->name=="piwo3"))
            if(isCollide(a, b))
        {
            if(b->name=="piwo1") sc->add_to_score(-350);
            if(b->name=="piwo2") sc->add_to_score(-300);
            if(b->name=="piwo3") sc->add_to_score(-600);
            a->life = 0;
            b->life = 0;
            Animation *anim = new Animation(t23, "simpson", 0, 0, 150, 150, 8, 0.2);
            anim->set_pos(b->x, b->y);
            animations.push_back(anim);

        }
        if((a->name=="handbullet" && b->name=="piwo1") || (a->name=="handbullet" && b->name=="piwo2") || (a->name=="handbullet" && b->name=="piwo3"))
            if(isCollide(a, b))
        {
            if(b->name=="piwo1") sc->add_to_score(500);
            if(b->name=="piwo2") sc->add_to_score(400);
            if(b->name=="piwo3") sc->add_to_score(800);
            a->life = 0;
            b->life = 0;
            Animation *anim = new Animation(t24, "happy", 0, 0, 150, 150, 4, 0.1);
            anim->set_pos(b->x, b->y);
            animations.push_back(anim);
        }
        if(a->name=="redbullet" && b->name=="bonus")
            if(isCollide(a, b))
        {
            if(b->name=="bonus") sc->add_to_score(0);
            a->life = 0;
            b->life = 0;
            Animation *anim = new Animation(t25, "sad", 0, 0, 150, 150, 18, 0.4);
            anim->set_pos(b->x, b->y);
            animations.push_back(anim);
        }
        if(a->name=="handbullet" && b->name=="bonus")
            if(isCollide(a, b))
        {
            if(b->name=="bonus") sc->add_to_score(10000);
            a->life = 0;
            b->life = 0;
            Animation *anim = new Animation(t26, "star", 0, 0, 200, 200, 7, 0.2);
            anim->set_pos(b->x, b->y);
            animations.push_back(anim);
        }
        if(a->name=="redbullet" && b->name=="rocket")
            if(isCollide(a, b))
        {
            a->life = 0;
            b->life--;
            if(b->life == 0)
            {
            if(b->name=="rocket") sc->add_to_score(1000);
            Animation *anim = new Animation(t20, "explosion", 0, 0, 200, 200, 17, 0.4);
            anim->set_pos(b->x, b->y);
            animations.push_back(anim);
            }

        }
        if(a->name=="handbullet" && b->name=="rocket")
            if(isCollide(a, b))
        {
            a->life = 0;
            b->life -= 1;
        }
    }
        if(a->name=="burger" || a->name=="fries")
            if(a->x < 0)
        {
            a->life = 0;
            sc->add_to_score(-50);
        }

        if(a->name=="piwo1" || a->name=="piwo2" || a->name=="piwo3")
            if(a->x < 0)
        {
            a->life = 0;
            sc->add_to_score(-200);
        }

        if(a->name=="rocket")
            if(a->x < 0)
        {
            a->life = 0;
            sc->add_to_score(-3000);
        }
        if(a->name=="bonus")
            if(a->x < 0)
        {
            a->life = 0;
            sc->add_to_score(0);
        }
    }
    }

    /// Draw ///

    window.clear();
    bg->update();
    bg->draw(window);

    END_GAME = gt->isEnd();
    if(END_GAME == false)
    {
    for(auto i=objects.begin();i!=objects.end();)
    {
        Object *o = *i;

        o->update();
        if(o->life == 0)
        {
            i=objects.erase(i);
            delete o;
        }
        else
        {
            i++;
        }
    }

    for(auto i=animations.begin();i!=animations.end();)
    {
        Animation *a = *i;

        a->update();
        if(a->IsEnd())
        {
            i=animations.erase(i);
            delete a;
        }
        else
        {
            i++;
        }
    }


    for(auto i:objects)
        i->draw(window);

    for(auto i:animations)
        i->draw(window);


    sc->update();
    sc->draw(window);

    gt->update();
    gt->draw(window);
    }
    else if(END_GAME == true) /// END GAME HAHAHEUAHUEHAHAHAHA ///
    {

     for(auto i=objects.begin();i!=objects.end();)
    {
        Object *o = *i;
        i=objects.erase(i);
        delete o;
    }

    for(auto i=animations.begin();i!=animations.end();)
    {
        Animation *a = *i;
        i=animations.erase(i);
        delete a;
    }

    /// END SCORE DISPLAY ///


    sc->end_game();
    sc->draw(window);
    endgame->update();
    endgame->draw(window);

    }

    window.display();

    }

    return 0;
}


