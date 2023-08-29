        CourseItem* pre = nullptr;
        CourseItem* current_links = current_tar->prerequisites;
        while (current_links != nullptr && strcmp(current_links->course->code, c) != 0)
        {
            pre = current_links;
            current_links = current_links->next;
        }
        if (current_links != nullptr)_