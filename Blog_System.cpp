#include <iostream>
#include <vector>
#include <string>

struct BlogPost {
    int id;
    std::string title;
    std::string content;
};

class BlogSystem {
private:
    std::vector<BlogPost> posts;
    int nextId;

public:
    BlogSystem() : nextId(1) {}

    void addPost() {
        std::cin.ignore(); // clear newline from previous input
        std::string title, content;

        std::cout << "Enter post title: ";
        std::getline(std::cin, title);

        std::cout << "Enter post content: ";
        std::getline(std::cin, content);

        posts.push_back({nextId++, title, content});
        std::cout << "Post added successfully!\n";
    }

    void listPosts() const {
        if (posts.empty()) {
            std::cout << "No posts available.\n";
            return;
        }
        std::cout << "Posts:\n";
        for (const auto& post : posts) {
            std::cout << "ID: " << post.id << " | Title: " << post.title << "\n";
        }
    }

    void viewPostContent() const {
        if (posts.empty()) {
            std::cout << "No posts to view.\n";
            return;
        }
        int id;
        std::cout << "Enter post ID to view content: ";
        std::cin >> id;

        for (const auto& post : posts) {
            if (post.id == id) {
                std::cout << "Title: " << post.title << "\n";
                std::cout << "Content:\n" << post.content << "\n";
                return;
            }
        }
        std::cout << "Post with ID " << id << " not found.\n";
    }

    void deletePost() {
        if (posts.empty()) {
            std::cout << "No posts to delete.\n";
            return;
        }
        int id;
        std::cout << "Enter post ID to delete: ";
        std::cin >> id;

        for (auto it = posts.begin(); it != posts.end(); ++it) {
            if (it->id == id) {
                posts.erase(it);
                std::cout << "Post deleted successfully.\n";
                return;
            }
        }
        std::cout << "Post with ID " << id << " not found.\n";
    }

    void run() {
        while (true) {
            std::cout << "\n=== Simple Blog System ===\n";
            std::cout << "1. Add Post\n";
            std::cout << "2. List Posts\n";
            std::cout << "3. View Post Content\n";
            std::cout << "4. Delete Post\n";
            std::cout << "5. Exit\n";
            std::cout << "Choose an option: ";

            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1:
                    addPost();
                    break;
                case 2:
                    listPosts();
                    break;
                case 3:
                    viewPostContent();
                    break;
                case 4:
                    deletePost();
                    break;
                case 5:
                    std::cout << "Exiting. Goodbye!\n";
                    return;
                default:
                    std::cout << "Invalid option. Please try again.\n";
            }
        }
    }
};

int main() {
    BlogSystem blog;
    blog.run();
    return 0;
}


