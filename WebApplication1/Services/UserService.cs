using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using WebApplication1.Data;
using WebApplication1.Models;
using WepApIBasicAuth.Iservice;


namespace WepApIBasicAuth.Services
{
    
    public  class UserService :IUserService
    {
        private readonly WebApplication1Context _context;
        public  bool ValidateCredentials(string username, string password)
        {
            User user = new User();
            Worker worker = new Worker();
            bool f = user.GetUsers(password, username);
            bool w= worker.GetWorkers(password, username);
            bool u = user.GetUsers(password, username);
            if (f==true)
          return  u;
            else
                return w;
        }

    }
}
