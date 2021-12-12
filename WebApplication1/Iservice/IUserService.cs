using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace WepApIBasicAuth.Iservice
{
    public interface IUserService
    {
        public bool ValidateCredentials(string username, string password);
    }
        
}
