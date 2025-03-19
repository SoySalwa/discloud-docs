#include "discloud/discloud.h"
#include "discloud/application.h" 
       
int main() {
   dcl::discloud discloud_token("YOUR_API_TOKEN_HERE");
 
   dcl::application status = getStatusApplication(discloud_token.getToken(), "/status" + "YOUR_APP_ID");

    return 0;
}
