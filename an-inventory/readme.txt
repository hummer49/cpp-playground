Exercise: Implementing a Simple Inventory Management System

Description:

You'll create a system to manage an inventory of products. 
Each product will have an ID, name, price, and quantity. 
The system should allow users to:

Add Products: Add new products to the inventory.
Remove Products: Remove products by their ID.
Update Product Information: Update the price and quantity of existing products.
Display Inventory: Display all products in the inventory, formatted neatly.
Search Products: Search for products by name (partial match).
Save/Load Inventory: Save the inventory to a text file and load it from a text file.
Requirements:

Use a Product class to represent each product.
Use std::vector or std::map to store the inventory. (Consider which one would be better for this scenario)
Implement input validation to handle invalid user input.
Use file I/O (std::fstream) to save and load the inventory.
Implement a menu-driven interface for user interaction.
Use std::string for product names.
Use std::stringstream to help with file I/O.
Handle potential exceptions (e.g., file I/O errors).