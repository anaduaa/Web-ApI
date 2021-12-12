using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using WebApplication1.Data;
using WepApIBasicAuth.Iservice;


namespace WepApIBasicAuth.Services
{
    
    public  class UserService :IUserService
    {
        private readonly WebApplication1Context _context;
        public  bool ValidateCredentials(string username, string password)
        {

            return (username.Equals("ws") && (password.Equals("123")));
            //var user = _context.User.Single(e => e.nname.Equals(username) && e.pass.Equals( password));

            //if (user != null)
            //{
            //    return true;


            //}
            //else return false;
        }

    }
}
