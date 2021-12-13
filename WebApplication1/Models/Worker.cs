using Microsoft.Data.SqlClient;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace WebApplication1.Models
{
    public class Worker
    {

        [Required(ErrorMessage = ("This feild is required"))]
        public string nname { get; set; }



        [Required(ErrorMessage = ("This feild is required"))]
        public string pass { get; set; }




        [Required(ErrorMessage = ("This feild is required"))]
        [Key]
        public string phone { get; set; }




        [Required(ErrorMessage = ("This feild is required"))]
        public string Work { get; set; }




        [Required(ErrorMessage = ("This feild is required"))]
        public string Experience { get; set; }




        [Required(ErrorMessage = ("This feild is required"))]
        public string Information { get; set; }



        [Required(ErrorMessage = ("This feild is required"))]
        public string token { get; set; }



        [Required(ErrorMessage = ("This feild is required"))]
        public string country { get; set; }



        [Required(ErrorMessage = ("This feild is required"))]
        public string NameFirst { get; set; }


        [Required(ErrorMessage = ("This feild is required"))]
        public string NameLast { get; set; }


        [Required(ErrorMessage = ("This feild is required"))]
        public string Available { get; set; }

        public bool GetWorkers(String password, string username)
        {
            string connectionString = "server=IMAD; database=WebApiSanayee;Trusted_Connection=True;";
            SqlConnection con = new SqlConnection(connectionString);
            con.Open();
            string sqlQuery = "SELECT TOP (1000) [phone],[nname],[pass],[Work],[Experience],[Information],[token],[country],[NameFirst],[NameLast],[Available] FROM[WebApiSanayee].[dbo].[Worker] ";
            SqlCommand cmd = new SqlCommand(sqlQuery, con);
            SqlDataReader dr = cmd.ExecuteReader();
            List<Worker> users = new List<Worker>();
            while (dr.Read())
            {
                Worker worker = new Worker();
                worker.nname = dr["nname"].ToString();
                worker.pass = dr["pass"].ToString();
                if (worker.nname.Equals(username) && worker.pass.Equals(password))
                {
                    return true;
                }
                users.Add(worker);
            }
            con.Close();

            return false;
        }

    }
}
