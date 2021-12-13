using Microsoft.AspNetCore.Authorization;
using System;

namespace WebApplication1.Controllers
{
    class BasicAuthorizationAttribute : AuthorizeAttribute
    {
        public BasicAuthorizationAttribute()
        {
            Policy = "BasicAuthentication";
        }
    }
}