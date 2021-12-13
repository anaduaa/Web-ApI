using Microsoft.Data.SqlClient;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace WebApplication1.Models
{
    public class User
    {


        [Key]
        public int ID { get; set; }
        [Required(ErrorMessage = ("This feild is required"))]
        public string nname { get; set; }
        [Required(ErrorMessage = ("This feild is required"))]
      
        [DataType(DataType.Password)]
        public string pass { get; set; }

        [Compare("pass", ErrorMessage = "Passwords are different")]
        [DataType(DataType.Password)]
        public String CoPassword { get; set; }


        [Required(ErrorMessage = ("This feild is required"))]
        [MaxLength(13, ErrorMessage = ("you should enter a valid phone number"))]
        public string phone { get; set; }
        
        public string token { get; set; }
       
        public string country { get; set; }
        [Required(ErrorMessage = ("This feild is required"))]
        public string NameFirst { get; set; }
        [Required(ErrorMessage = ("This feild is required"))]
        public string NameLast { get; set; }
        public List<User> GetUsers()
        { string connectionString = "server=IMAD; database=WebApiSanayee;Trusted_Connection=True;";
            SqlConnection con = new SqlConnection(connectionString);
            con.Open();
            string sqlQuery = "SELECT TOP (1000) [ID],[nname],[pass],[CoPassword],[phone],[token],[country],[NameFirst],[NameLast]FROM[WebApiSanayee].[dbo].[User] ";
            SqlCommand cmd = new SqlCommand(sqlQuery,con);
            SqlDataReader dr = cmd.ExecuteReader();
           List< User> users = new List<User>();
            while (dr.Read())
            {
                User user = new User();
                user.NameFirst = dr["NameFirst"].ToString();
                user.NameLast = dr["NameLast"].ToString();
                user.ID = Convert.ToInt32(dr["ID"]);
                users.Add(user);
            }con.Close();

            return users;
        }
        public bool GetUsers(String password,string username)
        {
            string connectionString = "server=IMAD; database=WebApiSanayee;Trusted_Connection=True;";
            SqlConnection con = new SqlConnection(connectionString);
            con.Open();
            string sqlQuery = "SELECT TOP (1000) [ID],[nname],[pass],[CoPassword],[phone],[token],[country],[NameFirst],[NameLast]FROM[WebApiSanayee].[dbo].[User]";
            SqlCommand cmd = new SqlCommand(sqlQuery, con);
            SqlDataReader dr = cmd.ExecuteReader();
            List<User> users = new List<User>();
            while (dr.Read())
            {
                User user = new User();
                user.nname = dr["nname"].ToString();
                user.pass = dr["pass"].ToString();
                if (user.nname.Equals(username) && user.pass.Equals(password))
                {
                    return true;
                }
                users.Add(user);
            }
            con.Close();

            return false;
        }
        public bool GetAdmin(String password, string username)
        {
            string connectionString = "server=IMAD; database=WebApiSanayee;Trusted_Connection=True;";
            SqlConnection con = new SqlConnection(connectionString);
            con.Open();
            string sqlQuery = "SELECT TOP (1000) [ID],[AdminName],[UserName],[MobileNumber],[Email],[Passw],[AdminRegdate] FROM[WebApiSanayee].[dbo].[tbladmins]";
            SqlCommand cmd = new SqlCommand(sqlQuery, con);
            SqlDataReader dr = cmd.ExecuteReader();
            List<User> users = new List<User>();
            while (dr.Read())
            {
                User user = new User();
                user.nname = dr["nname"].ToString();
                user.pass = dr["pass"].ToString();
                if (user.nname.Equals(username) && user.pass.Equals(password))
                {
                    return true;
                }
                users.Add(user);
            }
            con.Close();

            return false;
        }


    }

}
