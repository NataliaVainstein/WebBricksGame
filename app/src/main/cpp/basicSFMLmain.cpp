#include "isEngine/core/GameEngine.h"
#include "BricksGame/GameComponents/GameComponents.h"

namespace is
{
bool GameEngine::basicSFMLmain()
{
////////////////////////////////////////////////////////////
//                    WINDOW CREATION
////////////////////////////////////////////////////////////

//At this point we decided that we don't need it. And we will check it later.
#if 0
    m_window.create(sf::VideoMode(is::GameConfig::WINDOW_WIDTH,
                                  is::GameConfig::WINDOW_HEIGHT),
                                  is::GameConfig::GAME_NAME,
                                  is::getWindowStyle());

    // load application icon
    sf::Image iconTex;
    if (!iconTex.loadFromFile(is::GameConfig::GUI_DIR + "icon.png")) return false;
    m_window.setIcon(32, 32, iconTex.getPixelsPtr());


    setFPS(m_window, is::GameConfig::FPS); // set frames per second (FPS)
    sf::View m_view(sf::Vector2f(is::GameConfig::VIEW_WIDTH / 2.f, is::GameConfig::VIEW_HEIGHT / 2.f), sf::Vector2f(is::GameConfig::VIEW_WIDTH, is::GameConfig::VIEW_HEIGHT));
    m_window.setView(m_view);
    #endif
////////////////////////////////////////////////////////////
//                    INITIALIZATION
////////////////////////////////////////////////////////////
    sf::Vector2f frameDimensions(600, 800);
    sf::Vector2f framePosition(200, 100);

    GameComponents game(frameDimensions, framePosition);
////////////////////////////////////////////////////////////
//                    RENDER LOOP                         //
////////////////////////////////////////////////////////////
    game.run();
// This starts the render loop.                           //
// Don't touch unless you know what you're doing.         //
#if !defined(IS_ENGINE_HTML_5)                            //
    while (m_window.isOpen())                             //
#else                                                     //
    EM_ASM(console.log("Start successfully!");, 0);       //
    execMainLoop([&]                                      //
    {                                                     //
    if (emscripten_run_script_int("Module.syncdone") == 1)//
#endif                                                    //
    {                                                     //
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
//                       EVENT
////////////////////////////////////////////////////////////
 #if 0
      sf::Event event;
        while (m_window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    m_window.close();
                break;

				/* 					/!\ WARNING! /!\
				 * This code is no longer usefull (you can remove it)
				 *
                 * case sf::Event::Resized:
                 *    m_view.setSize(event.size.width, event.size.height);
                 *    m_view.setCenter(event.size.width / 2, event.size.height / 2);
                 *    m_window.setView(m_view);
                 * break;
				 */

                default: break;
            }
        }
    #endif

////////////////////////////////////////////////////////////
//                    UPDATE OBJECTS
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
//                     DRAW OBJECTS
////////////////////////////////////////////////////////////
    }

////////////////////////////////////////////////////////////
// Don't touch unless you know what you're doing.         //
    #if defined(IS_ENGINE_HTML_5)                         //
    });                                                   //
    #endif                                                //
////////////////////////////////////////////////////////////
    return true;
}
}
