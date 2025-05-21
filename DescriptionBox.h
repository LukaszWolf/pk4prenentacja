#ifndef DESCRIPTION_BOX
#define DESCRIPTION_BOX

#include <SFML/Graphics.hpp>
#include <vector>
#include "Item.h"

/**
 * \brief Displays a tooltip-like box next to an ItemSlot,
 * showing the item's name, type, and up to three non-zero stats.
 */
class DescriptionBox {
public:
    /**
     * @param font     Reference to an already-loaded SFML font.
     * @param charSize Character size for the text lines.
     */
    DescriptionBox(const sf::Font& font, unsigned int charSize = 14 );

    /**
     * Populate the box with information from the given item.
     * If item is nullptr, box will hide itself.
     */
    void setItem(Item* item);

    /**
     * Set the top-left position of the description box.
     */
    void setPosition(const sf::Vector2f& pos);

    /**
     * Control visibility independently of item presence.
     */
    void setVisible(bool show) { visible = show; }

    /**
     * Draw the box (if visible) onto the given window.
     */
    void draw(sf::RenderWindow& window);

private:
    const sf::Font& font;
    unsigned int characterSize;
    sf::RectangleShape background;
    std::vector<sf::Text> lines;
    bool visible;
    float padding;
    float lineSpacing;
    Item* item;

    // Recompute background size and layout all text lines
    void updateLayout();

    // Convert ItemType enum to human-readable string
    std::string typeToString(ItemType t) const;
};

#endif // DESCRIPTIONBOX_H


