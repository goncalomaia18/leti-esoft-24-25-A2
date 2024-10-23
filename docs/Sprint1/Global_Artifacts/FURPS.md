# Supplementary Specification (FURPS+)

## Functionality

_Specifies functionalities that:  
&nbsp; &nbsp; (i) are common across several US/UC;  
&nbsp; &nbsp; (ii) are not related to US/UC, namely: Audit, Reporting and Security._

- There should be logging and auditing of critical operations.
- All users must be authenticated in the system.
- The system must ensure that only authorized users (agents, store managers) have access to edit or delete property information.
- Sensitive information, such as client contact details and property pricing, must be encrypted.
- The system should generate reports on user activities like login attempts, property edits and transaction completions.
## Usability

_Evaluates the user interface. It has several subcategories,
among them: error prevention; interface aesthetics and design; help and
documentation; consistency and standards._

- Error messages should be descriptive and offer helpful suggestions for correcting the problem (e.g., invalid input for client registration).
- The system must provide a simple, clear, and consistent user interface across all platforms (web, mobile, console).
- Provide a help section or FAQ for common user issues (e.g., property search filters, how to contact agents).
- Consistent labeling and icons should be used across all screens to ensure uniformity and ease of use.
## Reliability
_Refers to the integrity, compliance and interoperability of the software. The requirements to be considered are: frequency and severity of failure, possibility of recovery, possibility of prediction, accuracy, average time between failures._

- The system must have an uptime of 99% or more per year to ensure high availability.
- In the event of system failure, the system should automatically recover without data loss.
- Failures should be logged, and administrators should be alerted for quick recovery actions.
- 
## Performance
_Evaluates the performance requirements of the software, namely: response time, start-up time, recovery time, memory consumption, CPU usage, load capacity and application availability._

- The system should start up in less than 10 seconds.
- Under heavy load, the response time must be no more than 5 seconds.
- The system should be able to handle high traffic during peak business hours without compromising performance.

## Supportability
_The supportability requirements gathers several characteristics, such as:
testability, adaptability, maintainability, compatibility,
configurability, instability, scalability and more._

- The system must be easily testable with automated unit and regression tests using the Google Testing Framework.
- The system must be compatible with multiple data persistence solutions (relational databases, NoSQL, in-memory databases).
- The system must be scalable to handle additional agencies, properties, and user accounts as Dream House expands.
- The system must be maintainable, with clear and well-documented code to support future upgrades.
- The system should be adaptable and easily extendable to accommodate new features, such as additional property types or new user interfaces.
## +

### Design Constraints

_Specifies or constraints the system design process. Examples may include: programming languages, software process, mandatory standards/patterns, use of development tools, class library, etc._

(fill in here)

### Implementation Constraints

_Specifies or constraints the code or construction of a system
such as: mandatory standards/patterns, implementation languages,
database integrity, resource limits, operating system._

(fill in here)

### Interface Constraints
_Specifies or constraints the features inherent to the interaction of the
system being developed with other external systems._

(fill in here)

### Physical Constraints

_Specifies a limitation or physical requirement regarding the hardware used to house the system, as for example: material, shape, size or weight._

(fill in here)