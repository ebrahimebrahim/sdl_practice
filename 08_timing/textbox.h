#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "logger.h"

class TextBox{
  public:

    TextBox(TTF_Font*, SDL_Color*, SDL_Renderer *, Logger *);
    /* Create a text box drawer, setting font and color.
    It is the user's responsibility to ensure that the font, color, logger, and renderer survive
    for the lifetime of the TextBox. The TextBox will not create or free these items.
    The font, color, renderer, logger can be changed by the user at any time by directly
    accessing the appropriate member variables */

    ~TextBox();

    int updateText(const char *);
    /* Update the text to be displayed, rendering a new texture which is stored internally.
    Return 0 on success and -1 on failure.
    Call this only if the text has changed.
    Currently it will always use SDL_ttf's blended mode (the slowest and prettiest),
    and it will also only handle LATIN1 characters.
    If a different text render mode is desired, or if unicode is needed, then
    the functionality here should be extended. */

    int renderCopy(int x, int y);
    /* Call SDL_RenderCopy on the renderer to draw the textbox at given location.
    Return 0 on success and negative error code on failure.
    The given location is the top left corner of the textbox. */


    /* Rect which will contain width and height of textbox after each call to updateText */
    SDL_Rect textRect = {0,0,0,0};


    SDL_Renderer * renderer = nullptr;
    TTF_Font * font = nullptr;
    SDL_Color * color = nullptr;
    Logger * log = nullptr;

  private:
    SDL_Texture * mTexture = nullptr;
    void freeTexture();

};
