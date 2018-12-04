#include<iostream>
#include <gflags/gflags.h>

DEFINE_bool(big_menu, true, "Include 'advanced' options in the menu listing");
DEFINE_string(image_path, "", "The image path");

int main(int argc, char** argv)
{
    gflags::SetVersionString("1.0.0.0");
    gflags::SetUsageMessage("Usage : ./demo ");
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    
    std::cout << "GFLAGS Data is: " << FLAGS_big_menu << std::endl;
    std::cout << "Image path is: " << FLAGS_image_path << std::endl;
}
