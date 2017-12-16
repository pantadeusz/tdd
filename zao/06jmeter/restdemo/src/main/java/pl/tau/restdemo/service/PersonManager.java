package pl.tau.restdemo.service;

// w oparciu o przyklad J Neumanna, przerobiony przez T Puzniakowskiego

import java.sql.Connection;
import java.sql.SQLException;
import java.util.List;

import pl.tau.restdemo.domain.Person;

public interface PersonManager {
	public Connection getConnection();
	public void deletePerson(Person person) throws SQLException;
	public void clearPersons() throws SQLException;
	public int addPerson(Person person);
	public Person getPerson(Person person);
	public List<Person> getAllPersons();

}
