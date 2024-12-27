#include "../../headers/views/AuthMenuView.h"
#include "../../headers/views/CategoriesMenuView.h"

AuthMenuView::AuthMenuView(const wstring &userToken) {
    this->userToken = userToken;
    this->headers = {L"Registered User Options!"};

    this->menuOptions = {
            L"Categories Management",
            L"Tasks Management"
    };

    this->cancelMenuMsg = L"Return";
}

int AuthMenuView::processMenuOption(int option) {
    int result = 0;
    BaseView *view;
    switch (option) {
        case 1:
            view = new CategoriesMenuView(this->userToken);
            view->show();
            break;
        default:
            result = -1;
            break;
    }
    return result;
}